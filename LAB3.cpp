using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LAB_3
{
    class SINHVIENK60
    {
        string hoten;
        long namsinh = 2000;
        float cao, nang;
        public SINHVIENK60()
        {
            hoten = "Nguyễn Đoàn Sĩ Nguyên";
            cao = 1.6F;
            nang = 55;
        }
        public SINHVIENK60(string ht,float c,float n)
        {
            hoten = ht;
            cao = c;
            nang = n;
        }
        public SINHVIENK60(SINHVIENK60 sv)
        {
            hoten = sv.hoten;
            cao = sv.cao;
            nang = sv.nang;
        }
        public void Sinhvien()
        {
            Console.WriteLine("{0}\t{1}\t{2}\t{3}", hoten, namsinh, cao, nang);
        }
        public void Suckhoe()
        {
            float BMI = nang / (cao * cao);
            float can = 0;
            if (BMI > 25)
            {
                Console.WriteLine("Béo phì.");
                    can = 25  * (cao * cao);
                Console.WriteLine("Can giam {0} kg", nang - can);
            }
            else
                if (BMI < 19)
                {
                    Console.WriteLine("Gầy ốm.");
                    can = 19 * (cao * cao);
                    Console.WriteLine("Can tang {0} kg", can - nang);
                }
                else
                    Console.WriteLine("Sức khỏe tốt.");
        }
    }
    class Phanso
    {
        int tuso;
        int mauso;
        public Phanso()
        {
            tuso = 0;
            mauso = 1;
        }
        public Phanso(int tu,int mau)
        {
            tuso = tu;
            mauso = mau;
        }
        public Phanso(Phanso ps)
        {
            tuso = ps.tuso;
            mauso = ps.mauso;
        }
        /*public int BCNN(int a,int b)
        {
            return (a * b) / UCLN(a, b);
        }*/
        public Phanso Cong(Phanso ps)
        {
            Phanso kq = new Phanso();
            kq.tuso = tuso * ps.mauso + ps.tuso * mauso;
            kq.mauso = mauso * ps.mauso;
            return kq;
        }
        public Phanso Tru(Phanso ps)
        {
            Phanso kq = new Phanso();
            kq.tuso = tuso * ps.mauso - ps.tuso * mauso;
            kq.mauso = mauso * ps.mauso;
            return kq;
        }
        public Phanso Nhan(Phanso ps)
        {
            Phanso kq = new Phanso();
            kq.tuso = tuso * ps.tuso;
            kq.mauso = mauso * ps.mauso;
            return kq;
        }
        public Phanso Chia(Phanso ps)
        {
            Phanso kq = new Phanso();
            kq.tuso = tuso * ps.mauso;
            kq.mauso = mauso * ps.tuso;
            return kq;
        }
        public int UCLN(int a, int b)
        {
            a = Math.Abs(a);
            b = Math.Abs(b);
            while(a!=b)
            {
                if (a > b)
                    a = a - b;
                else
                    b = b - a;
            }
            return a;
        }
        public Phanso Rutgon()
        {
            Phanso kq = new Phanso();
            kq.tuso = tuso / UCLN(tuso,mauso);
            kq.mauso = mauso / UCLN(tuso,mauso);
            return kq;
        }
        public void Xuat()
        {
            Console.WriteLine("\t{0}/{1}", tuso, mauso);
        }
        public static Phanso operator +(Phanso ps1, Phanso ps2)
        {
            Phanso kq = new Phanso();
            kq.tuso = ps1.tuso * ps2.mauso + ps2.tuso * ps1.mauso;
            kq.mauso = ps1.mauso * ps2.mauso;
            return kq;
        }
        public static Phanso operator -(Phanso ps1, Phanso ps2)
        {
            Phanso kq = new Phanso();
            kq.tuso = ps1.tuso * ps2.mauso - ps2.tuso * ps1.mauso;
            kq.mauso = ps1.mauso * ps2.mauso;
            return kq;
        }
        public static Phanso operator *(Phanso ps1, Phanso ps2)
        {
            Phanso kq = new Phanso();
            kq.tuso = ps1.tuso * ps2.tuso;
            kq.mauso = ps1.mauso * ps2.mauso;
            return kq;
        }
        public static Phanso operator /(Phanso ps1, Phanso ps2)
        {
            Phanso kq = new Phanso();
            kq.tuso = ps1.tuso * ps2.mauso;
            kq.mauso = ps1.mauso * ps2.tuso;
            return kq;
        }
    }
    class Monhoc
    {
        string mahp, tenhp;
        byte donvihoctrinh;
        float tylekiemtra, diemkiemtra, diemthi;
        public byte dvht { get => donvihoctrinh; set => donvihoctrinh = value; }
        public float tlkt { get => tylekiemtra; set => tylekiemtra = value; }
        public float dkt { get => diemkiemtra; set => diemkiemtra = value; }
        public float dt { get => diemthi; set => diemthi = value; }
        public Monhoc()
        {
            mahp = "OOP_60CNTT3";
            tenhp = "Lập trình hướng đối tượng";
            donvihoctrinh = 2;
            tylekiemtra = 0.6F;
            diemkiemtra = 8;
            diemthi = 6.5F;
        }
        public Monhoc(string ma = "",string ten = "",byte dvht = 0,float tlkt = 0,float dkt = 0,float dt = 0)
        {
            mahp = ma; tenhp = ten; donvihoctrinh = dvht; tylekiemtra = tlkt; diemkiemtra = dkt;diemthi = dt;
        }
        public float Diemtrungbinh()
        {
            return tylekiemtra * diemkiemtra + (1 - tylekiemtra) * diemthi;
        }
        public void Xuat()
        {
            Console.WriteLine("Môn: {0}", tenhp);
            Console.WriteLine("Điểm kiểm tra: {0}", diemkiemtra);
            Console.WriteLine("Điểm thi: {0}", diemthi);
            Console.WriteLine("Điểm trung bình: {0}",Diemtrungbinh());
        }
    }
    class Sinhvien
    {
        string maso, hoten;
        Monhoc[] mh;
        int n;
        public Sinhvien()
        {
            maso = "60136321";
            hoten = "Nguyễn Đoàn Sĩ Nguyên";
        }
        public Sinhvien(string ms,string ht)
        {
            maso = ms;
            hoten = ht;
        }
        public void Nhapds()
        {
            Console.Write("Nhap so luong mon hoc: ");
            n = Convert.ToInt16(Console.ReadLine());
            mh = new Monhoc[n];
            string ma, ten;
            byte dvht;
            float tlkt, dkt, dt;
            for(int i = 0; i < n; i++)
            {
                Console.Write("Nhap ma mon hoc: ");
                ma = Console.ReadLine();
                Console.Write("Nhap ten mon hoc: ");
                ten = Console.ReadLine();
                Console.Write("Nhap so don vi hoc trinh: ");
                dvht = Convert.ToByte(Console.ReadLine());
                Console.Write("Nhap ty le kiem tra: ");
                tlkt = Convert.ToSingle(Console.ReadLine());
                Console.Write("Nhap diem kiem tra: ");
                dkt = Convert.ToSingle(Console.ReadLine());
                Console.Write("Nhap diem thi: ");
                dt = Convert.ToSingle(Console.ReadLine());
                mh[i] = new Monhoc(ma, ten, dvht, tlkt, dkt, dt);
            }
        }
        public float Dtbhocki()
        {
            float Tdiem = 0, Tdv = 0;
            for(int i = 0; i < n; i++)
            {
                Tdiem = Tdiem + mh[i].Diemtrungbinh() * mh[i].dvht;
                Tdv = Tdv + mh[i].dvht;
            }
            return Tdiem / Tdv;
        }
        public float Dtbtichluy()
        {
            float Tdiem = 0, Tdv = 0;
            for (int i = 0; i < n; i++)
            {
                if (mh[i].Diemtrungbinh() > 5)
                {
                    Tdiem = Tdiem + mh[i].Diemtrungbinh() * mh[i].dvht;
                    Tdv = Tdv + mh[i].dvht;
                }
            }
            if (Tdv == 0)
                return 0;
            else
                return Tdiem / Tdv;
        }
        public void Xethocbong()
        {
            if(Dtbhocki()>7)
            {
                int dk = 0;
                for (int i = 0; i < n; i++)
                    if (mh[i].dkt > 5.5 && mh[i].dt > 5.5)
                        dk++;
                if (dk == n)
                    Console.WriteLine("Sinh viên đủ điều kiện nhận học bổng.");
                else
                    Console.WriteLine("Sinh viên không đủ điều kiện nhận học bổng.");
            }
            else
                Console.WriteLine("Sinh viên không đủ điều kiện nhận học bổng.");
        }
        public void Xuat()
        {
            Console.WriteLine("Mã số sinh viên: {0}", maso);
            Console.WriteLine("Họ và tên: {0}", hoten);
            Console.WriteLine("Điểm trung bình học kỳ: {0}", Dtbhocki());
            Console.WriteLine("Điểm trung bình tích lũy: {0}", Dtbtichluy());
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Console.InputEncoding = Encoding.Unicode;
            Console.OutputEncoding = Encoding.Unicode;
            SINHVIENK60 sv = new SINHVIENK60();
            sv.Sinhvien();
            sv.Suckhoe();
            SINHVIENK60 sv1 = new SINHVIENK60("Nguyễn Đoàn Sĩ Nguyên", 1.6F, 45);
            sv1.Sinhvien();
            sv1.Suckhoe();
            SINHVIENK60 sv2 = new SINHVIENK60(sv);
            sv2.Sinhvien();
            sv2.Suckhoe();
            Phanso ps1 = new Phanso(4,7);
            Phanso ps2 = new Phanso(3,5);
            ps1.Xuat();
            ps2.Xuat();
            //Cộng 2 phân số dùng phương thức thành phần
            Console.Write("Cộng 2 phân số dùng phương thức thành phần:");
            Phanso ps3 = new Phanso();
            ps3 = ps1.Cong(ps2);
            ps3 = ps3.Rutgon();
            ps3.Xuat();
            //dùng toán tử
            Console.Write("Cộng 2 phân số dùng toán tử:");
            ps3 = ps1 + ps2;
            ps3 = ps3.Rutgon();
            ps3.Xuat();
            Console.WriteLine();
            //Trừ 2 phân số dùng phương thức thành phần
            Console.Write("Trừ 2 phân số dùng phương thức thành phần:");
            ps3 = ps1.Tru(ps2);
            ps3 = ps3.Rutgon();
            ps3.Xuat();
            //dùng toán tử
            Console.Write("Trừ 2 phân số dùng toán tử:");
            ps3 = ps1 - ps2;
            ps3 = ps3.Rutgon();
            ps3.Xuat();
            Console.WriteLine();
            //Nhân 2 phân số dùng phương thức thành phần
            Console.Write("Nhân 2 phân số dùng phương thức thành phần:");
            ps3 = ps1.Nhan(ps2);
            ps3 = ps3.Rutgon();
            ps3.Xuat();
            //dùng toán tử
            Console.Write("Nhân 2 phân số dùng toán tử:");
            ps3 = ps1 * ps2;
            ps3 = ps3.Rutgon();
            ps3.Xuat();
            Console.WriteLine();
            //Chia 2 phân số dùng phương thức thành phần
            Console.Write("Chia 2 phân số dùng phương thức thành phần:");
            ps3 = ps1.Chia(ps2);
            ps3 = ps3.Rutgon();
            ps3.Xuat();
            //dùng toán tử
            Console.Write("Chia 2 phân số dùng toán tử:");
            ps3 = ps1 / ps2;
            ps3 = ps3.Rutgon();
            ps3.Xuat();
            Console.WriteLine();
            Sinhvien s = new Sinhvien();
            s.Nhapds();
            s.Xuat();
            s.Xethocbong();
            Console.ReadKey();
        }
    }
}
