using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Bai20
{
    class Program
    {
        interface ILamViec
        {
            string LamViec(string mota);
        }
        public class NhanVien : ILamViec
        {
            public int Ma { get; set; }
            public string Ten { get; set; }

            public string LamViec(string mota)
            {
                string s = "Nhân viên đang [" + mota + "]";
                return s;
            }

            public void TinhLuong()
            {
                Console.WriteLine("Đây là phương thức tính lương của NhanVien");
            }
            public virtual int TinhLuong(int ngayCong)
            {
                return ngayCong * 100;
            }
        }
        public class NhanVienChinhThuc : NhanVien
        {
            public new void TinhLuong()
            {
                base.TinhLuong();
                Console.WriteLine(" Đây là phương thức tính lương của NhanVienChinhThuc");
            }
            public override int TinhLuong(int ngayCong)
            {
                if (ngayCong == 20)
                    return 10000000;
                return base.TinhLuong(ngayCong);
            }
        }
        public class NhanVienThoiVu : NhanVien
        {
            public new void TinhLuong()
            {
                Console.WriteLine("Đây là phương thức tính lương của NhanVienThoiVu");
            }
        }
        public class SinhVien : ILamViec
        {
            public string MaSV { get; set; }
            public string TenSV { get; set; }
            public string LamViec(string mota)
            {
                string s = "Sinh viên đang [" + mota + "]";
                return s;
            }
        }
        public class HinhChuNhat
        {
            public int CanhA { get; set; }
            public int CanhB { get; set; }
            public HinhChuNhat(int canhA, int canhB)
            {
                CanhA = canhA;
                CanhB = canhB;
            }
            public virtual int DienTich()
            {
                return CanhA * CanhB;
            }
            public virtual int ChuVi()
            {
                return (CanhA + CanhB) * 2;
            }
        }
        public class HinhHoc
        {
            public virtual int TinhDienTich()
            {
                return 0;
            }
        }
        public class HinhTron : HinhHoc
        {
            public override int TinhDienTich()
            {
                return 1;
            }
        }
        public class HinhVuong : HinhChuNhat
        {

            public HinhVuong(int a) : base(a, a)
            {

            }
            public override int DienTich()
            {
                return base.DienTich();
            }
            public override int ChuVi()
            {
                return base.ChuVi();
            }
        }
        static void TestNhanVien()
        {
            NhanVienChinhThuc teo = new NhanVienChinhThuc();
            teo.Ma = 1;
            teo.Ten = "Nguyễn Văn Tèo";
            Console.WriteLine("Lương của "+teo.Ten+" = ");
            teo.TinhLuong();

            NhanVienThoiVu ty = new NhanVienThoiVu();
            ty.Ma = 2;
            ty.Ten = "Tý tý";
            Console.WriteLine("Lương của "+ty.Ten+":");
            ty.TinhLuong();
        }
        static void TestNhanVien2()
        {
            NhanVienChinhThuc teo = new NhanVienChinhThuc();
            int luong=teo.TinhLuong(20);
            Console.WriteLine("Lương của Tèo="+luong);
        }
        static void TestHinhHoc()
        {
            HinhHoc h;
            h = new HinhHoc();
            Console.WriteLine("Diện tích = "+h.TinhDienTich());

            h = new HinhTron();
            Console.WriteLine("Diện tích = " + h.TinhDienTich());
        }
        static void TestHinhChuNhatHinhVuong()
        {
            HinhChuNhat h1 = new HinhChuNhat(4,10);

            Console.WriteLine("Chu vi="+h1.ChuVi());
            Console.WriteLine("Diện tích=" + h1.DienTich());

            HinhChuNhat h2 = new HinhVuong(7);
            Console.WriteLine("Chu vi=" + h2.ChuVi());
            Console.WriteLine("Diện tích=" + h2.DienTich());

            HinhVuong h3 = new HinhVuong(6);
            Console.WriteLine("Chu vi=" + h3.ChuVi());
            Console.WriteLine("Diện tích=" + h3.DienTich());

        }
        static void TestInterface()
        {
            ILamViec teo = new NhanVien();
            Console.WriteLine(teo.LamViec("Báo cáo kinh doanh"));

            ILamViec ty = new SinhVien();
            Console.WriteLine(ty.LamViec("Đang học bài C#"));
        }
        static void TestHocAsVaIs()
        {
            List<ILamViec> ds = new List<ILamViec>();
            NhanVien teo = new NhanVien() { Ma = 1, Ten = "tèo" };
            ds.Add(teo);
            SinhVien ty = new SinhVien() { MaSV="sv1",TenSV="Tý"};
            ds.Add(ty);
            ds.Add(new NhanVien() { Ma=2,Ten="Bin"});

            foreach(ILamViec i in ds)
            {
                if(i is NhanVien)
                {
                    NhanVien nv = i as NhanVien;
                    Console.WriteLine("==>Nhân viên " + nv.Ten);
                }
                else if(i is SinhVien)
                {
                    SinhVien sv = i as SinhVien;
                    Console.WriteLine("==>Sinh viên " + sv.TenSV);
                }
            }
            
        }
        static void Main(string[] args)
        {
            Console.OutputEncoding = Encoding.UTF8;
            TestHocAsVaIs();
            TestNhanVien();
            TestNhanVien2();
            //TestInterface();
            //TestHinhHoc();
            //TestHinhChuNhatHinhVuong();
            Console.ReadLine();
        }
    }
}
