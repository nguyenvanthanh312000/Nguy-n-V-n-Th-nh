using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Baitap1
{
    class Nguoi
    {
        string maso, hoten;
        byte ngaysinh;
        public Nguoi()
        {
            maso = "";
            hoten = "";
            ngaysinh = 0;
        }
        public Nguoi(string ms,string ht,byte ns)
        {
            maso = ms;
            hoten = ht;
            ngaysinh = ns;
        }
        public override string ToString()
        {
            return maso + " " + hoten + " " + ngaysinh;
        }
    }
    class Nhanvien : Nguoi
    {
        float hesoluong;
        int luongcoban;
        byte songay;
        public float hsl { get => hesoluong; set => hesoluong = value; }
        public int lcb { get => luongcoban; set => luongcoban = value; }
        public byte sn { get => songay; set => songay = value; }
        public Nhanvien():base()
        {
            hesoluong = 0;
            luongcoban = 0;
            songay = 0;
        }
        public Nhanvien(string ms, string ht, byte ns,float hsl, int lcb, byte sn) : base(ms, ht, ns)
        {
            hesoluong = hsl;
            luongcoban = lcb;
            songay = sn;
        }
        public float Tienluong()
        {
            if (songay > 26)
                return hesoluong * luongcoban + hesoluong * luongcoban * 0.1F;
            else
                return hesoluong * luongcoban;
        }
        public void Xuat()
        {
            Console.WriteLine(base.ToString());
            Console.WriteLine("He so luong: {0}", hesoluong);
            Console.WriteLine("Luong co ban: {0}", luongcoban);
            Console.WriteLine("So ngay lam viec: {0}", songay);
            Console.WriteLine("Tien luong: {0}\n", Tienluong());
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            FileStream f = new FileStream("D://data3.txt", FileMode.Open);
            StreamReader rd = new StreamReader(f, Encoding.UTF8);
            List<Nhanvien> ls = new List<Nhanvien>();
            //Nhap ds nhan vien
            try
            {
                while (!rd.EndOfStream)
                {
                    string maso = rd.ReadLine();
                    string hoten = rd.ReadLine();
                    byte ngaysinh = byte.Parse(rd.ReadLine());
                    float hesoluong = float.Parse(rd.ReadLine());
                    int luongcoban = int.Parse(rd.ReadLine());
                    byte songay = byte.Parse(rd.ReadLine());
                    Nhanvien v = new Nhanvien(maso, hoten, ngaysinh, hesoluong, luongcoban, songay);
                    ls.Add(v);
                }
            }
            catch
            {
                Console.WriteLine("Khong mo duoc file!");
            }
            //Sap xep nhan vien giam dan he so luong
            for(int i = 0; i < ls.Count; i++)
                for(int j = 0; j < ls.Count; j++)
                    if(ls[i].hsl > ls[j].hsl)
                    {
                        Nhanvien tam = new Nhanvien();
                        tam = ls[i];
                        ls[i] = ls[j];
                        ls[j] = tam;
                    }
            foreach (var h in ls)
                h.Xuat();
            Console.WriteLine("Nhap thong tin nhan vien can them:");
            Console.Write("Ma so nhan vien:");
            string ms = Console.ReadLine();
            Console.Write("Ten nhan vien:");
            string ht = Console.ReadLine();
            Console.Write("Ngay sinh:");
            byte ns = byte.Parse(Console.ReadLine());
            Console.Write("He so luong:");
            float hsl = float.Parse(Console.ReadLine());
            Console.Write("Luong co ban:");
            int lcb = int.Parse(Console.ReadLine());
            Console.Write("So ngay lam viec:");
            byte sn = byte.Parse(Console.ReadLine());
            Nhanvien nv = new Nhanvien(ms, ht, ns, hsl, lcb, sn);
            ls.Add(nv);
            Console.WriteLine("--------------------------------------");
            foreach (var h in ls)
                h.Xuat();
            int x;
            for(x = 0; x < ls.Count; x++)
            {
                if (ls[x].sn < 10)
                {
                    ls.RemoveAt(x);
                    break;
                }
            }
            Console.WriteLine("--------------------------------------");
            foreach (var h in ls)
                h.Xuat();
            Console.ReadKey();
        }
    }
}
