using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp4
{
    class Hocvien:IComparable<Hocvien>
    {
        private string ma,hoten;
        private int gioitinh;
        private DateTime Ngaysinh;
        private int hocphi;

        public string Ma { get => ma; set => ma = value; }
        public Hocvien(string m = " ", string t = " ", int gt = 0, DateTime ngay=new DateTime(),int hp = 0)
        {
            ma = m;
            hoten = t;
            gioitinh = gt;
            Ngaysinh = ngay;
            hocphi = hp;
        }
        public override string ToString()
        {
            if (gioitinh==1)
                return "Mã số " +ma + " họ tên " + hoten + " nam " + Ngaysinh.ToShortDateString() + " số tiền học phí " + hocphi;
            else
                return "Mã số " +ma + " họ tên " + hoten + " nữ " + Ngaysinh.ToShortDateString() + " số tiền học phí " + hocphi;
        }
        public int CompareTo(Hocvien h)
        {
            if (hocphi >h.hocphi)
                return 1;
            else if (hocphi == h.hocphi)
                return 0;
            else
                return -1;
        }
    }
    class Khoahoc
    {
        string ten;
        byte soluong;
        List<Hocvien> ls = new List<Hocvien>();
        public Khoahoc(string t = " ",byte sl = 0)
        {
            
            ten = t;
            soluong = sl;
            for(byte i = 0;i<soluong;i++)
            {
                //nhap thong tin cho hoc vien
                Console.WriteLine("Nhập thông tin học viên thứ {0}", i + 1);
                Console.Write("Nhập mã = ");
                string m = Console.ReadLine();
                Console.Write("Nhập họ tên : ");
                string ht = Console.ReadLine();
                Console.Write("Nhập giới Tính(Nam/Nữ) nếu chọn 1 là nam 2 là nữ : ");
                int gt = int.Parse(Console.ReadLine());
                Console.Write("Nhập ngày sinh : ");
                DateTime ngay = DateTime.Parse(Console.ReadLine());
                DateTime.Now.ToString("dd/MM/yyyy");
                Console.Write("Nhập học phí : ");
                int hp = int.Parse(Console.ReadLine());
                Hocvien hv = new Hocvien(m, ht, gt, ngay, hp);
                ls.Add(hv);
            }
        }
        public void Xuat()
        {
            ls.Sort();
            foreach (var h in ls)
                Console.WriteLine(h.ToString());
        }
        public void Tim(string x)
        {
            foreach (var h in ls)
                if (x.CompareTo(h.Ma) == 0)
                    Console.WriteLine(h.ToString());
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Console.OutputEncoding = Encoding.UTF8;
            Khoahoc khoa = new Khoahoc("LT HDT ", 1);
            khoa.Xuat();
            Console.WriteLine("Nhập vào 1 mã số sinh viên cần tìm : ");
            string x = Console.ReadLine();
            khoa.Tim(x);
            Console.ReadKey();
        }
    }
}
