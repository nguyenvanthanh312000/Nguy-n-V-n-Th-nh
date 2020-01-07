using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace ConsoleApp2
{
    public class Phone
    {
        //Khai báo các biến lớp
        public string maso, nhanhieu;
        public int dongia;
        public DateTime namsx;
        public string Maso { get => maso; set => maso = value; }
        public string Nhan { get => nhanhieu; set => nhanhieu = value; }
        // Khai Báo Contructor có tham số
        public Phone(string ma = "", string nhan = "", int dg = 0, DateTime nam = new DateTime())
        {
            maso = ma; 
            nhanhieu = nhan; 
            dongia = dg; 
            namsx = nam;
        }
        public float Gia()
        {
            // nếu giá lớn hơn 1 thì giá bán = đơn giá + 5%
            if (namsx.Year > 1)
                return dongia + dongia * 0.05F;
            else
            // ngược lại đơn giá + 15%
                return dongia + dongia * 0.15F;
        }
        public override string ToString()
        {
            return maso + " Nhãn Hiệu " + nhanhieu + " Đơn GIá " + dongia + " Năm sản xuất " + namsx + " " + Gia();
        }
    }

    // SmartPhone Kế thừa từ Phone
    public class SmartPhone : Phone, IComparable<SmartPhone>
    {
        //Khai báo các biến 
        public byte Mpixel, mem;
        public SmartPhone(string ma = "", string nhan = "", int dg = 0, DateTime nam = new DateTime(), byte m = 0, byte g = 0) : base(ma, nhan, dg, nam)
        {
            Mpixel = m;
            mem = g;
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
        // Hàm xuất ToString
        public override string ToString()
        {
            return "Mã số :"+Maso + "\tNhãn Hiệu : " + Nhan + "\tMáy Ảnh:" + Mpixel + "M\tDung Lượng Bộ Nhớ :" + mem + "GB\t\tGiá:" + Giaban();
        }
        public int CompareTo(SmartPhone x)
        {
            if (string.Compare(Nhan, x.Nhan) > 1)
                return 1;
            else
                if (string.Compare(Nhan, x.Nhan) < 1)
                return -1;
            else
                return 0;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            // Thêm tiếng việt
            Console.OutputEncoding = Encoding.UTF8;
            // Đọc file 
            FileStream f = new FileStream("C:\\BT\\data0111.txt", FileMode.Open);
            StreamReader rd = new StreamReader(f, Encoding.UTF8);
            // Tạo List danh sách
            List<SmartPhone> ls = new List<SmartPhone>();
            //Nhập Ds n SmartPhone
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
                    // Thêm vào danh sách
                    SmartPhone s = new SmartPhone(maso, nhanhieu, dongia, namsx, mpi, mem);
                    ls.Add(s);
                }
            }
            catch
            {
                Console.WriteLine("Không mở được File");
            }
            // sắp xếp giảm dần
            ls.Sort();
            foreach (var h in ls)
                Console.WriteLine(h.ToString());
            // Xuất SmartPhone cao nhất
            double max = 0;
            foreach (var h in ls)
            {
                if (max < h.Giaban())
                    max = h.Giaban();
            }
            Console.WriteLine("\nCác SmartPhone có giá cao nhất:");
            foreach (var h in ls)
                if (h.Giaban() == max)
                    Console.WriteLine(h.ToString());
            // Đếm và in số lượng SmartPhone của nhãn hiệu x , x nhập vào 
            Console.Write("\nNhãn hiệu SmartPhone cần tìm: ");
            string x = Console.ReadLine();
            byte dem = 0;
            foreach (var h in ls)
            {
                if (string.Compare(x, h.Nhan) == 0)
                {
                    Console.WriteLine(h.ToString());
                    dem++;
                }
            }
            Console.WriteLine("Số lượng SmartPhone nhãn hiệu {0}: {1}", x, dem);
            // Chèn 1 Smart Phone vào ds
            Console.WriteLine("\nNhập SmartPhone cần thêm vào:");
            Console.Write("Mã số : ");
            string ms = Console.ReadLine();
            Console.Write("Nhãn hiệu: ");
            string nh = Console.ReadLine();
            Console.Write("Đơn giá: ");
            int dg = int.Parse(Console.ReadLine());
            Console.Write("Ngày Tháng Năm Sản Xuất : ");
            DateTime nsx = DateTime.Parse(Console.ReadLine());
            Console.Write("Camera: ");
            byte mpx = byte.Parse(Console.ReadLine());
            Console.Write("Dung lượng bộ nhớ: ");
            byte gb = byte.Parse(Console.ReadLine());
            SmartPhone sp1 = new SmartPhone(ms, nh, dg, nsx, mpx, gb);
            // chạy vòng for 
            for (int i = 0; i < ls.Count; i++)
            {
                if (string.Compare(nh, ls[i].Nhan) == 0)
                {
                    // chèn
                    ls.Insert(i, sp1);
                    break;
                }
            }
            Console.WriteLine("Chèn 1 SmartPhone:");
            foreach (var h in ls)
                Console.WriteLine(h.ToString());
            Console.ReadKey();
        }
    }
}
