using System;
using System.Text;

namespace LAB_2
{
    class GiaiPTB2
    {
        int a; int b; int c;
        public void Nhap(int a1, int b1, int c1)
        {
            a = a1;
            b = b1;
            c = c1;
        }
        private void PTB1()
        {
            if (b == 0)
                if (c == 0)
                    Console.WriteLine("Phuong trinh vo so nghiem.");
                else
                    Console.WriteLine("Phuong trinh vo nghiem.");
            else
            {
                Console.WriteLine("Nghiem x= {0}", Convert.ToDouble(-b) / Convert.ToDouble(a));
            }
        }
        public void PTB2()
        {
            if (a == 0)
                PTB1();
            else
            {
                int delta = b * b - 4 * a * c;
                if (delta > 0)
                {
                    Console.WriteLine("Nghiem cua phuong trinh:");
                    Console.WriteLine("x1 = {0}", (Convert.ToDouble(-b) + Math.Sqrt(delta)) / Convert.ToDouble(2 * a));
                    Console.WriteLine("x2 = {0}", (Convert.ToDouble(-b) - Math.Sqrt(delta)) / Convert.ToDouble(2 * a));
                }
                else
                    if (delta == 0)
                        Console.WriteLine("x = {0}", Convert.ToDouble(-b) / Convert.ToDouble(2 * a));
                    else
                        Console.WriteLine("Phuong trinh vo nghiem.");
            }
        }
    }
    class Mang
    {
        int[] A;
        int n;
        public void Nhapmang(int n1)
        {
            n = n1;
            A = new int[n];
            for(int i = 0; i < n
                ; i++)
            {
                Console.Write("A[{0}] = ", i);
                A[i] = Convert.ToInt16(Console.ReadLine());
            }
        }
        public void Xuatmang()
        {
            Console.WriteLine("Cac phan tu cua mang:");
            for(int i = 0; i < n; i++)
                Console.Write("\t{0}", A[i]);
            Console.WriteLine();
        }
        public float TBCong()
        {
            float Tong = 0;
            for (int i = 0; i < n; i++)
            {
                Tong = Tong + A[i];
            }
            return Tong / n;
        }
        public void Sapxep()
        {
            for(int i=0; i < n-1; i++)
                for(int j = i+1; j < n; j++)
                    if (A[i] > A[j])
                    {
                        int tam = A[i];
                        A[i] = A[j];
                        A[j] = tam;
                    }
            Console.WriteLine("Mang sau khi sap xep:");
            for(int i = 0; i < n; i++)
                Console.Write("\t{0}", A[i]);
            Console.WriteLine();
        }
    }
    
    public class Student
    {
        string id, name;
        int birthday;
        bool male;
        //Khởi tạo không tham số
        public Student()
        {
            id = "60130940";
            name = "Nguyễn Văn Thạnh";
            birthday = 19;
            male = true;
        }
        //Khởi tạo có tham số
        public Student(string id1,string name1,int birthday1,bool male1)
        {
            id = id1;
            name = name1;
            birthday = birthday1;
            male = male1;
        }
        //Khởi tạo sao chép
        public Student(Student s)
        {
            id = s.id;
            name = s.name;
            birthday = s.birthday;
            male = s.male;
        }
        public void Xuatsinhvien()
        {
            if (male)
                Console.WriteLine("{0}\t{1}\t{2}\tNam", id, name, birthday);
            else
                Console.WriteLine("{0}\t{1}\t{2}\tNu", id, name, birthday);
        }
    }
    class Chuoi
    {
        string s;
        int x, y;
        int cao = Console.WindowHeight;
        int rong = Console.WindowWidth;
        public Chuoi()
        {
            s = "Welcome to Summoner's Rift";
            x = 10;
            y = 22;
            Console.BackgroundColor = ConsoleColor.White;
            Console.ForegroundColor = ConsoleColor.Black;
        }
        public Chuoi(string s1,int x1,int y1)
        {
            s = s1;
            x = x1;
            y = y1;
            Console.BackgroundColor = ConsoleColor.White;
            Console.ForegroundColor = ConsoleColor.Black;
        }
        public void Hienthi()
        {
            Console.Clear();
            Console.CursorTop = x;
            Console.CursorLeft = y;
            Console.WriteLine(s);
            Console.CursorVisible = false;
        }
        public void Chuyendong()
        {
            ConsoleKeyInfo cd;
            while (true)
            {
                cd = Console.ReadKey(true);
                if (cd.Key == ConsoleKey.LeftArrow)
                    y--;
                if (cd.Key == ConsoleKey.RightArrow)
                    y++;
                if (cd.Key == ConsoleKey.UpArrow)
                    x--;
                if (cd.Key == ConsoleKey.DownArrow)
                    x++;
                if (cd.Key == ConsoleKey.Escape)
                    break;
                if (y == -1)
                    y++;
                if (y > rong-s.Length)
                    y--;
                if (x == -1)
                    x++;
                if (x > cao)
                    x--;
                Hienthi();
            }
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            GiaiPTB2 pt = new GiaiPTB2();
            int a, b, c;
            Console.Write("a = ");
            a = Convert.ToInt16(Console.ReadLine());
            Console.Write("b = ");
            b = Convert.ToInt16(Console.ReadLine());
            Console.Write("c = ");
            c = Convert.ToInt16(Console.ReadLine());
            pt.Nhap(a, b, c);
            pt.PTB2();
            Mang m = new Mang();
            int n;
            do
            {
                Console.Write("n = ");
                n = Convert.ToInt16(Console.ReadLine());
            } while (n < 3 || n > 20);
            m.Nhapmang(n);
            m.Xuatmang();
            Console.WriteLine("Trung binh cong cac phan tu cua mang: {0}", m.TBCong());
            m.Sapxep();
            Console.InputEncoding = Encoding.Unicode;
            Console.OutputEncoding = Encoding.Unicode;
            Student St = new Student();//Khởi tạo không tham số
            St.Xuatsinhvien();
            Student St1 = new Student("60130940", "Nguyễn Văn Thạnh", 19, true);//Khởi tạo có tham số
            St1.Xuatsinhvien();
            Student St2 = new Student(St);
            St2.Xuatsinhvien();
            Console.ReadKey();
            Chuoi ch = new Chuoi("Welcome to Summoner's Rift",10,22);
            ch.Hienthi();
            ch.Chuyendong();
        }
    }
}
