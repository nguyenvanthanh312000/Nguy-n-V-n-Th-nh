using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BT_1
{
    class Program
    {
        static void BaiTap()
        {
            string mssv, hoten;
            short namsinh;
            bool gioitinh;
            Console.Write("Ma so sinh vien: ");
            mssv = Console.ReadLine();
            Console.Write("Ho Ten: ");
            hoten = Console.ReadLine();
            Console.Write("Nam sinh: ");
            namsinh = Convert.ToInt16(Console.ReadLine());
            Console.Write("Gioi Tinh: ");
            gioitinh = Convert.ToBoolean(Console.ReadLine());
            if (gioitinh)
                Console.WriteLine("{0}\t{1}\t{2}\tnam", mssv, hoten, namsinh);
            else
                Console.WriteLine("{0}\t{1}\t{2}\tnu", mssv, hoten, namsinh);
        }
        static void Bai1()
        {
            int a, b;
            Console.Write("a = ");
            a = Convert.ToInt32(Console.ReadLine());
            Console.Write("b = ");
            b = Convert.ToInt32(Console.ReadLine());
            if (a == 0)
                if (b == 0)
                    Console.WriteLine("Phuong trinh vo so nghiem.");
                else
                    Console.WriteLine("Phuong trinh vo nghiem.");
            else
                Console.WriteLine("x = {0}", Convert.ToDouble(-b) / Convert.ToDouble(a));
        }
        static void Bai2()
        {
            int thang, nam;
            Console.Write("Thang: ");
            thang = Convert.ToInt16(Console.ReadLine());
            Console.Write("Nam: ");
            nam = Convert.ToInt16(Console.ReadLine());
            if (thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 8 || thang == 10 || thang == 12)
                Console.WriteLine("Co 31 ngay.");
            if (thang == 4 || thang == 6 || thang == 9 || thang == 11)
                Console.WriteLine("Co 30 ngay.");
            if (thang == 2)
                if (nam % 4 == 0)
                    Console.WriteLine("Co 29 ngay.");
                else
                    Console.WriteLine("Co 28 ngay.");
        }
        static void Bai3()
        {
            int n;
            int S = 0;
            do
            {
                Console.Write("n = ");
                n = Convert.ToInt16(Console.ReadLine());
            } while (n < 10 || n > 1000);
            int a;
            for (int i = 0; i < n; i++)
            {
                a = Convert.ToInt16(Math.Sqrt(i));
                if (i == a*a)
                    S += i;
            }
            Console.WriteLine("Tong cac so chinh phuong nho hon n: {0}", S);
        }
        static void Bai4()
        {
            int a, b, c;
            Console.Write("a = ");
            a = Convert.ToInt16(Console.ReadLine());
            Console.Write("b = ");
            b = Convert.ToInt16(Console.ReadLine());
            Console.Write("c = ");
            c = Convert.ToInt16(Console.ReadLine());
            if (a == 0)
            {
                if(b == 0)
                    if (c == 0)
                        Console.WriteLine("Phuong trinh vo so nghiem.");
                    else
                        Console.WriteLine("Phuong trinh vo nghiem.");
                else
                    Console.WriteLine("x = {0}", -c / b);
            }
            else
            {
                double delta = b * b - 4 * a * c;
                if (delta > 0)
                {
                    Console.WriteLine("Phuong trinh co hai nghiem:");
                    Console.WriteLine("x1 = {0}", (Convert.ToDouble(-b) + Math.Sqrt(delta)) / Convert.ToDouble(2 * a));
                    Console.WriteLine("x2 = {0}", (Convert.ToDouble(-b) - Math.Sqrt(delta)) / Convert.ToDouble(2 * a));
                }
                else
                {
                    if (delta == 0)
                        Console.WriteLine("Phuong trinh co nghiem kep x = {0}", Convert.ToDouble(-b) / Convert.ToDouble(2 * a));
                }
            }
        }
        static void Bai5()
        {
            int[] A;
            int n;
            do
            {
                Console.Write("n = ");
                n = Convert.ToInt16(Console.ReadLine());
            } while (n < 3 || n > 20);
            A = new int[2*n];
            for(int i = 0; i < n; i++)
            {
                Console.Write("Phan tu {0} = ", i);
                A[i] = Convert.ToInt16(Console.ReadLine());
            }
            Console.WriteLine("Cac phan tu cua mang: ");
            for(int i = 0; i < n; i++)
                Console.WriteLine("\t{0}", A[i]);
            for(int i = 0; i < n-1; i++)
            {
                for(int j = i + 1; j < n; j++)
                    if(A[i] > A[j])
                    {
                        int tam = A[i];
                        A[i] = A[j];
                        A[j] = tam;
                    }
            }
            int tong = 0;
            for (int i = 0; i < n; i++)
                if (A[i] % 2 == 1)
                    tong++;
            Console.WriteLine("Tong cac so le trong mang: {0}", tong);
            int x,vt;
            Console.WriteLine("Phan tu can them: ");
            x = Convert.ToInt16(Console.ReadLine());
            Console.WriteLine("Vi tri can them: ");
            vt = Convert.ToInt16(Console.ReadLine());
            n++;
            for (int i = n; i >= vt; i--)
                A[i] = A[i-1];
            A[vt-1] = x;
            Console.WriteLine("Cac phan tu cua mang: ");
            for (int i = 0; i < n; i++)
                Console.WriteLine("\t{0}", A[i]);
        }
        static void Main(string[] args)
        {
            BaiTap();
            Bai1();
            Bai2();
            Bai3();
            Bai4();
            Bai5();
            Console.ReadKey();
        }
    }
}
