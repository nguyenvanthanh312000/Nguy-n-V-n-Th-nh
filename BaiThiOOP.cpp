using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace ConsoleApp2
{
    class Phone
    {
        string maso, nhanhieu;
        int dongia;
        DateTime namsx;
        public string Maso { get => maso; set => maso = value; }
        public string Nhan { get => nhanhieu; set => nhanhieu = value; }
        public Phone(string ma = "", string nhan = "", int dg = 0,DateTime nam =new DateTime())
        {
            maso = ma; nhanhieu = nhan; dongia = dg; namsx = nam;
        }
        public float Gia()
        {
            if (namsx.Year > 1)
                return dongia + dongia * 0.05F;
            else
                return dongia + dongia * 0.15F;
        }
        public override string ToString()
        {
            return maso + " " + nhanhieu + " " + dongia + " " + namsx + " " + Gia();
        }
    }
    class SmartPhone : Phone, IComparable <SmartPhone>
    {
        byte Mpixel, mem;
        public SmartPhone(string ma = "", string nhan = "", int dg = 0, DateTime nam = new DateTime(), byte Mpx = 0, byte GB = 0) : base(ma, nhan, dg, nam)
        {
            Mpixel = Mpx; mem = GB;
        }
        public float Giaban()
        {
            if (mem > 32)
                return Gia() + Gia() * 0.15F;
            else
            {
                if (mem > 16)
                    return Gia() + Gia() * 0.05F;
                else
                    return Gia();
            }
        }
        public override string ToString()
        {
            return Maso + "\t" + Nhan + "\tCamera:" + Mpixel + "Mpixel\tMem:" + mem + "GB\tGia:" + Giaban();
        }
        public int CompareTo(SmartPhone sp)
        {
            if (string.Compare(Nhan, sp.Nhan) > 1)
                return 1;
            else
                if (string.Compare(Nhan, sp.Nhan) < 1)
                    return -1;
                else
                    return 0;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            FileStream f = new FileStream("D:\\data01.txt", FileMode.Open);
            StreamReader rd = new StreamReader(f, Encoding.UTF8);
            List<SmartPhone> ls = new List<SmartPhone>();
            //a
            try
            {
                while (!rd.EndOfStream)
                {
                    string maso = rd.ReadLine();
                    string nhanhieu = rd.ReadLine();
                    int dongia = int.Parse(rd.ReadLine());
                    DateTime namsx = DateTime.Parse(rd.ReadLine());
                    byte mpi = byte.Parse(rd.ReadLine());
                    byte mem = byte.Parse(rd.ReadLine());
                    SmartPhone sp = new SmartPhone(maso, nhanhieu, dongia, namsx, mpi, mem);
                    ls.Add(sp);
                }
            }
            catch
            {
                Console.WriteLine("Khong doc duoc File");
            }
            //b
            ls.Sort();
            foreach (var h in ls)
                Console.WriteLine(h.ToString());
            //c
            float max = 0;
            foreach(var h in ls)
            {
                if (max < h.Giaban())
                    max = h.Giaban();
            }
            Console.WriteLine("\nCac SmartPhone co gia cao nhat:");
            foreach (var h in ls)
                if (h.Giaban() == max)
                    Console.WriteLine(h.ToString());
            //d
            Console.Write("\nNhan hieu can tim: ");
            string x = Console.ReadLine();
            byte dem = 0;
            foreach(var h in ls)
            {
                if(string.Compare(x,h.Nhan)==0)
                {
                    Console.WriteLine(h.ToString());
                    dem++;
                }
            }
            Console.WriteLine("So luong SmartPhone nhan hieu {0}: {1}", x, dem);
            //e
            Console.WriteLine("\nSmartPhone can them:");
            Console.Write("Ma so: ");
            string ms = Console.ReadLine();
            Console.Write("Nhan hieu: ");
            string nh = Console.ReadLine();
            Console.Write("Don gia: ");
            int dg = int.Parse(Console.ReadLine());
            Console.Write("Nam san xuat: ");
            DateTime nsx = DateTime.Parse(Console.ReadLine());
            Console.Write("Camera: ");
            byte mpx = byte.Parse(Console.ReadLine());
            Console.Write("Dung luong: ");
            byte gb = byte.Parse(Console.ReadLine());
            SmartPhone sp1 = new SmartPhone(ms, nh, dg, nsx, mpx, gb);
            for (int i = 0; i < ls.Count; i++)
            {
                if (string.Compare(nh, ls[i].Nhan) == 0)
                {
                    ls.Insert(i, sp1);
                    break;
                }
            }
            Console.WriteLine("Chen 1 SmartPhone:");
            foreach (var h in ls)
                Console.WriteLine(h.ToString());
            Console.ReadKey();
        }
    }
}
