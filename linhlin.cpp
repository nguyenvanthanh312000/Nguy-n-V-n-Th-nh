using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace demothicntt2
{
    class SmartPhone:Phone,IComparable<SmartPhone>
    {
        int camera;
        int rom;

      
        public string nhanhieu1()
        {
            return Nhanhieu;
        }
        public SmartPhone(string m = "", string nh = "", int d = 0, int n = 0, int c = 0, int r = 0) : base(m, nh, d, n)
        {
            camera = c;
            rom = r;
           
        }
        public override string ToString()
        {
            return "Ma so: " + maso + "\tNhan hieu: " + Nhanhieu +"\tDon gia: "+dongia+ "\tNam: " + nam+"\tCamera: "+camera+"\tRom: "+rom+"\tGia ban: "+Giaban1();

        }
        public  double Giaban1()
        {
            if (rom <= 16)
                return Giaban();
            else if (rom > 16 && rom <= 32)
                return Giaban() * (double)1.05;
            else
                return Giaban() * (double)1.15;
        }
        // Giam dan
        public int CompareTo(SmartPhone s)
        {
            return s.Nhanhieu.CompareTo(this.Nhanhieu);
        }
        /*public int CompareTo(SmartPhone s)
        {
            if (String.Compare(this.nhanhieu, s.nhanhieu, true) < 0) return 1;
            else if (String.Compare(this.nhanhieu, s.nhanhieu, true) == 0) return 0;
            else return -1;
        }*/

        // Tang dan
        //public int CompareTo(SmartPhone s)
        //{
        //    return this.Nhanhieu.CompareTo(s.Nhanhieu);
        //}

    }
}



using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
namespace demothicntt2
{
    class Program
    {
        static void Main(string[] args)
        {
            int n;
            do
            {
                Console.WriteLine("Nhap so luong smartphone: ");
                n = int.Parse(Console.ReadLine());
            } while (n < 2 || n > 30);
            List<SmartPhone> ls = new List<SmartPhone>();
            try
            {
                FileStream f = new FileStream("D:\\smart.txt", FileMode.Open);
                StreamReader rd = new StreamReader(f, Encoding.UTF8);
                for(int i = 0; i < n; i++)
                {
                    string maso = rd.ReadLine();
                    string nhanhieu = rd.ReadLine();
                    int dongia = int.Parse(rd.ReadLine());
                    int nam = int.Parse(rd.ReadLine());
                    int camera = int.Parse(rd.ReadLine());
                    int rom = int.Parse(rd.ReadLine());
                    SmartPhone sm = new SmartPhone(maso, nhanhieu, dongia, nam, camera, rom);
                    ls.Add(sm);
                }
            }
            catch
            {
                Console.WriteLine("Khong doc duoc file!!\a");
            }

            ls.Sort();
            foreach (SmartPhone h in ls)
            {
                Console.WriteLine(h.ToString());
            }
            double max = 0;
            foreach (SmartPhone sm in ls)
            {
                if (sm.Giaban1() > max)
                    max = sm.Giaban1();
            }
           
            foreach (SmartPhone sm in ls)
            {
                if (sm.Giaban1() == max)
                {
                    Console.WriteLine("SmartPhone co gia ban cao nhat: ");
                    Console.WriteLine(sm.ToString());
                    break;
                }
            }
            max = 0;
            Console.WriteLine("Nhap nhan hieu can dem: ");
            string x = Console.ReadLine();
            foreach(SmartPhone h in ls)
            {
                if (h.nhanhieu1() == x)
                {
                    max++;
                }
            }
            Console.WriteLine("So luong nhan hieu can tim: {0}", max);
       
            Console.WriteLine("Nhap Ma so: ");
                    string maso1 = Console.ReadLine();
            Console.WriteLine("Nhap nhan hieu: ");
                    string nhanhieu1 = Console.ReadLine();
            Console.WriteLine("Nhap don gia: ");
                    int dongia1 = int.Parse(Console.ReadLine());
            Console.WriteLine("Nhap nam: ");
                    int nam1 = int.Parse(Console.ReadLine());
            Console.WriteLine("Nhap Camera: ");
                    int camera1= int.Parse(Console.ReadLine());
            Console.WriteLine("Nhap rom: ");
                    int rom1 = int.Parse(Console.ReadLine());
                    SmartPhone sm1 = new SmartPhone(maso1, nhanhieu1, dongia1, nam1, camera1, rom1);
            ls.Add(sm1);
            ls.Sort();
            foreach (SmartPhone h in ls)
            {
                Console.WriteLine(h.ToString());
            }
            Console.ReadKey();
        }
    }
}
