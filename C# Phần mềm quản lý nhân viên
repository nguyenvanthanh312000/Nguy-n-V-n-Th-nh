using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Bai21
{
    public class NhanVien
    {
        public const long LUONG_CO_BAN = 10000000;
        public int MaNhanVien { get; set; }
        public string TenNhanVien { get; set; }
        public DateTime NgaySinh { get; set; }
        public LoaiChuVu ChucVu { get; set; }
        public PhongBan Phong { get; set; }
        public long TinhLuong
        {
            get
            {
                if (ChucVu == LoaiChuVu.GIAM_DOC)
                    return LUONG_CO_BAN + (long)(LUONG_CO_BAN * 0.25);
                if (ChucVu == LoaiChuVu.TRUONG_PHONG)
                    return LUONG_CO_BAN + (long)(LUONG_CO_BAN * 0.15);
                if (ChucVu == LoaiChuVu.PHO_PHONG)
                    return LUONG_CO_BAN + (long)(LUONG_CO_BAN * 0.05);
                return LUONG_CO_BAN;
            }
        }
        public override string ToString()
        {
            return this.MaNhanVien + "\t"
                   + this.TenNhanVien + "\t"
                   + this.ChucVu + "\t==>"
                   + this.TinhLuong;
        }
    }
    public enum LoaiChuVu
    {
        GIAM_DOC,
        TRUONG_PHONG,
        PHO_PHONG,
        NHAN_VIEN
    }
    public class PhongBan
    {
        private List<NhanVien> dsNv = new List<NhanVien>();
        public int MaPhongBan { get; set; }
        public string TenPhongBan { get; set; }
        public NhanVien TruongPhong { get; set; }
        public bool ThemNhanVien(NhanVien nv)
        {
            bool trungMaNV = false;
            foreach (NhanVien oldNV in dsNv)
                if (oldNV.MaNhanVien == nv.MaNhanVien)
                {
                    trungMaNV = true;
                    break;
                }
            if (trungMaNV == true)
                return false;
            nv.Phong = this;
            dsNv.Add(nv);
            return true;
        }
        public void XuatToanBoNhanVien()
        {
            foreach (NhanVien nv in dsNv)
            {
                Console.WriteLine(nv);
            }
        }
        public NhanVien TimNhanVien(int maNv)
        {
            foreach (NhanVien old in dsNv)
                if (old.MaNhanVien == maNv)
                    return old;
            return null;
        }
        public bool XoaNhanVien(int maNV)
        {
            NhanVien nv = TimNhanVien(maNV);
            if (nv == null) return false;
            dsNv.Remove(nv);
            return true;
        }
        private int compare(NhanVien nv1, NhanVien nv2)
        {
            int kqSSTen = string.Compare(nv1.TenNhanVien, nv2.TenNhanVien, true);
            if (kqSSTen == 0)
            {
                if (nv1.MaNhanVien < nv2.MaNhanVien)
                    return 1;
                if (nv1.MaNhanVien > nv2.MaNhanVien)
                    return -1;
                return 0;
            }
            return kqSSTen;
        }
        public void SapXep()
        {
            dsNv.Sort(compare);
        }
        public long TongLuong()
        {
            long sum = 0;
            foreach (NhanVien nv in dsNv)
                sum += nv.TinhLuong;
            return sum;
        }
    }
    class Program
    {
        static List<PhongBan> dsPB = new List<PhongBan>();
        static void TestQLNV()
        {
            PhongBan pNS = new PhongBan();
            pNS.MaPhongBan = 1;
            pNS.TenPhongBan = "Phòng Nhân Sự";
            dsPB.Add(pNS);

            NhanVien teo = new NhanVien();
            teo.MaNhanVien = 1;
            teo.TenNhanVien = "Tèo";
            teo.ChucVu = LoaiChuVu.TRUONG_PHONG;
            pNS.ThemNhanVien(teo);

            NhanVien ty = new NhanVien();
            ty.MaNhanVien = 2;
            ty.TenNhanVien = "Tèo";
            ty.ChucVu = LoaiChuVu.NHAN_VIEN;
            pNS.ThemNhanVien(ty);

            NhanVien met = new NhanVien();
            met.MaNhanVien = 100;
            met.TenNhanVien = "Mẹt ơi Mẹt";
            met.ChucVu = LoaiChuVu.NHAN_VIEN;
            pNS.ThemNhanVien(met);

            PhongBan pkt = new PhongBan();
            pkt.MaPhongBan = 2;
            pkt.TenPhongBan = "Phòng Kế Toán";
            dsPB.Add(pkt);

            NhanVien bin = new NhanVien();
            bin.MaNhanVien = 3;
            bin.TenNhanVien = "Bin bin bin ";
            bin.ChucVu = LoaiChuVu.PHO_PHONG;
            pkt.ThemNhanVien(bin);

            NhanVien thanh = new NhanVien();
            thanh.MaNhanVien = 4;
            thanh.TenNhanVien = " Nguyễn Văn Thạnh";
            thanh.ChucVu = LoaiChuVu.GIAM_DOC;
            pkt.ThemNhanVien(thanh);

            Console.WriteLine("Danh sách toàn bộ nhân viên trong công ty:");

            foreach (PhongBan pb in dsPB)
            {
                Console.WriteLine(pb.TenPhongBan);
                pb.XuatToanBoNhanVien();
            }
            NhanVien old = pkt.TimNhanVien(3);
            if (old != null)
            {
                old.TenNhanVien = "Bỉm bỉm bỉm";
            }

            Console.WriteLine("Danh sách toàn bộ nhân viên trong công ty sau khi sửa:");

            foreach (PhongBan pb in dsPB)
            {
                Console.WriteLine(pb.TenPhongBan);
                pb.XuatToanBoNhanVien();
            }
            if (pNS.XoaNhanVien(113) == false)
            {
                Console.WriteLine("Không tìm thấy mã nhân viên =113 để xóa");
            }
            else
            {
                Console.WriteLine("Danh sách toàn bộ nhân viên trong công ty sau khi xóa:");

                foreach (PhongBan pb in dsPB)
                {
                    Console.WriteLine(pb.TenPhongBan);
                    pb.XuatToanBoNhanVien();
                }
            }

            Console.WriteLine("Danh sách nhân viên thuộc phòng Nhân Sự:");
            pNS.XuatToanBoNhanVien();
            pNS.SapXep();
            Console.WriteLine("Danh sách nhân viên thuộc phòng Nhân Sự sau khi sắp xếp:");
            pNS.XuatToanBoNhanVien();

            long sum = 0;
            foreach (PhongBan pb in dsPB)
                sum += pb.TongLuong();
            Console.WriteLine("Tổng lương phải thanh toán cho 1 tháng ={0}", sum);
        }
        static void Main(string[] args)
        {
            Console.OutputEncoding = Encoding.UTF8;
            TestQLNV();
            Console.ReadLine();
        }
    }
}
