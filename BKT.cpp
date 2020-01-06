using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace BAIKIEMTRABOSUNG_THANH_60CNTT3
{
    class Nguoi
    {
        int maso;
        string hoten;
        int Namsinh;
        public int ms { get => maso; set => maso = value; }
        // tạo contructer không tham số
        public Nguoi()
        {
            maso = 0;
            hoten = " ";
            Namsinh = 0;
        }
        // tạo contructer có tham số
        public Nguoi(int ms, string ht, int ns)
        {
            maso = ms;
            hoten = ht;
            Namsinh = ns;
        }
        // hàm xuất Tostring
        public override string ToString()
        {
            return " \nMã Số " + maso + " \nHọ tên : " + hoten + " \nNăm Sinh " + Namsinh;
        }
    }
    // hàm nhân viên kế thừa từ người
    class Nhanvien : Nguoi
    {
        double hesoluong;
        int sosanpham;
        int tiencong;
        public double hsl { get => hesoluong; set => hesoluong = value; }
        public int ssp { get => sosanpham; set => sosanpham = value; }
        public int tc { get => tiencong; set => tiencong = value; }

        // tạo contructer không tham số kế thừa từ người
        public Nhanvien() : base()
        {
            hesoluong = 0;
            sosanpham = 0;
            tiencong = 0;
        }
        // tạo contructer có tham số kế thừa từ người
        public Nhanvien(int mso, string hten, int nsinh, double hsluong, int sspham, int tcong) : base(mso, hten, nsinh)
        {
            hesoluong = hsluong;
            sosanpham = sspham;
            tiencong = tcong;
        }
        // sử dụng if để tính tiền lương
        public double Tienluong()
        {
            if (sosanpham > 100)
                return sosanpham * tiencong + sosanpham * tiencong * 0.1F;
            else
                return sosanpham * tiencong;
        }
        public void Xuat()
        {
            Console.WriteLine(base.ToString());
            Console.WriteLine("Hệ số lương : {0}", hesoluong);
            Console.WriteLine("Số lượng sản phẩm là: {0}", sosanpham);
            Console.WriteLine("Tiền công là : {0}", tiencong);
            Console.WriteLine("Tiền lương là: {0}\n", Tienluong());
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            // tạo tiếng việt 
            Console.OutputEncoding = Encoding.UTF8;
            int n;
            // đọc file
            FileStream f = new FileStream("C://Baikiemtrabosung_Thanh60CNTT3//Baikiemtrabosung_Thanh60CNTT3.txt", FileMode.Open);
            StreamReader rd = new StreamReader(f, Encoding.UTF8);
            //tạo list danh sách
            List<Nhanvien> ds = new List<Nhanvien>();
            do
            {
                Console.Write("Nhập n nhân viên: ");
                n = int.Parse(Console.ReadLine());
            } while (n <= 2 || n >= 10);

            try
            {
                while (!rd.EndOfStream)
                {
                    int maso = int.Parse(rd.ReadLine());
                    string hoten = rd.ReadLine();
                    int namsinh = int.Parse(rd.ReadLine());
                    double hesoluong = double.Parse(rd.ReadLine());
                    int sosanpham = int.Parse(rd.ReadLine());
                    int tiencong = int.Parse(rd.ReadLine());
                    Nhanvien v = new Nhanvien(maso, hoten, namsinh, hesoluong, sosanpham, tiencong);
                    ds.Add(v);
                }
            }
            catch
            {
                Console.WriteLine("Xuất ra thông tin nhân viên !");
            }
            //sắp xếp giảm dần nhân viên
            for (int i = 0; i < ds.Count; i++)
                for (int j = 0; j < ds.Count; j++)
                    if (ds[i].ms > ds[j].ms)
                    {
                        Nhanvien tam = new Nhanvien();
                        tam = ds[i];
                        ds[i] = ds[j];
                        ds[j] = tam;
                    }
            foreach (var h in ds)
                h.Xuat();
            // nhập vào thông tin nhân viên cần thêm vào
            Console.WriteLine("Nhập thông tin nhân viên cần thêm vào :");
            Console.Write("Mã số nhân viên :");
            int mso = int.Parse(Console.ReadLine());
            Console.Write("Tên nhân viên :");
            string hten = Console.ReadLine();
            Console.Write("năm sinh :");
            int nsinh = int.Parse(Console.ReadLine());
            Console.Write("Hệ số tiền lương :");
            double hsluong = double.Parse(Console.ReadLine());
            Console.Write("Số lượng sản phẩm:");
            int sspham = int.Parse(Console.ReadLine());
            Console.Write("Số tiền công của nhân viên :");
            int tcong = int.Parse(Console.ReadLine());
            Nhanvien nv = new Nhanvien(mso, hten, nsinh, hsluong, sspham, tcong);
            ds.Add(nv);
            Console.WriteLine("--------------");
            foreach (var h in ds)
                h.Xuat();
            int x;
            for (x = 0; x < ds.Count; x++)
            {
                if (ds[x].ssp < 10)
                {
                    ds.RemoveAt(x);
                    break;
                }
            }
            Console.WriteLine("-----------------");
            foreach (var h in ds)
                h.Xuat();
            Console.ReadKey();
        }
    }
}
