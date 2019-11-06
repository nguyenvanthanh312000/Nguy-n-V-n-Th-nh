using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp7
{

    class Motor
    {
        protected string name, color;
        protected byte speed;
        public Motor(string n = "", string c = "Xe Rùa ", byte s = 30)
        {
            this.name = n; this.color = c; this.speed = s;
        }
        public void Run()
        {
            Console.WriteLine(".. Xe Đang Chạy...");
        }
        public void Speed_Up(byte v)
        {
            speed = v;
            Console.WriteLine("Với Vận Tốc {0} km/h", speed);
        }
        //chồng phương thức ToString()
        public override string ToString()
        {
            return name + " Màu " + color;
        }
    }
    //class Xe máy
    class Motobike : Motor
    {
        static byte seat;//so cho ngoi
        public Motobike(string n = "Xe Máy EXciter Của Thạnh ", string c = "Trắng_Đỏ", byte s = 40) : base(n, c, s)
        {
            seat = 2;
        }
    }
    //class Xe hơi
    class Car : Motor
    {
        byte seat;//so cho ngoi
        public Car(string n = "Xe Hơi BMW Của Thạnh ", string c = "Đỏ_Trắng", byte s = 40) : base(n, c, s)
        {
            seat = 5;
        }
    }

    class ANIMAL
    {
        string ten;
        byte sochan;
        byte cannang;

        public ANIMAL(string ten = "", byte sochan = 0, byte cannang = 0)
        {
            this.ten = ten;
            this.sochan = sochan;
            this.cannang = cannang;
        }

        public virtual void Keu()
        {
            Console.WriteLine("Tiếng Kêu:");
        }

        public virtual void thucan()
        {
            Console.WriteLine("Thức ăn:");
        }
        public override string ToString()
        {
            return ten + " Số Chân " + sochan.ToString() + " Nặng  " + cannang.ToString() + "kg";
        }

    }
    class Ga : ANIMAL
    {
        public Ga(string ten = "Gà", byte sochan = 2, byte cannang = 2) : base(ten, sochan, cannang) { }
        public override void Keu()
        {
            base.Keu();
            Console.WriteLine("Ò ó O");
        }

        public override void thucan()
        {
            base.thucan();
            Console.WriteLine("Thóc , Lúa ");
        }

        public override string ToString()
        {
            return base.ToString();
        }
    }
    class Cho : ANIMAL
    {
        public Cho(string ten = "Chó", byte sochan = 4, byte cannang = 5) : base(ten, sochan, cannang) { }
        public override void Keu()
        {
            base.Keu();
            Console.WriteLine("Gâu Gâu");
        }

        public override void thucan()
        {
            base.thucan();
            Console.WriteLine("Thịt Xương ");
        }

        public override string ToString()
        {
            return base.ToString();
        }
    }
    class Meo : ANIMAL
    {
        public Meo(string ten = "Mèo", byte sochan = 4, byte cannang = 2) : base(ten, sochan, cannang) { }
        public override void Keu()
        {
            base.Keu();
            Console.WriteLine("Meow Meow");
        }

        public override void thucan()
        {
            base.thucan();
            Console.WriteLine("Chuột");
        }

        public override string ToString()
        {
            return base.ToString();
        }
    }

    //class Program
    class Program
    {
        static void BT1()
        {
            byte chon;//chọn loại xe
            Console.WriteLine("Chọn 1.(Motorbike) Là Xe Máy (50km/h) ");
            Console.WriteLine("Chọn 2.(Car) là Xe Hơi BMW (100km/h) ");
            Console.WriteLine("Chọn Số Khác Là Xe Rùa (30km/h) ");
            Console.Write("Mời Bạn Chọn Số : ");
            //nhập 1 là Motorbike

            chon = byte.Parse(Console.ReadLine());
            if (chon == 1)
            {
                Motobike mb = new Motobike();
                Console.WriteLine(mb.ToString());
                mb.Run();
                mb.Speed_Up(50);
            }
            else if (chon == 2)
            {
                Car c = new Car();
                Console.WriteLine(c.ToString());
                c.Run();
                c.Speed_Up(100);
            }
            else
            {
                Motor m = new Motor();
                Console.WriteLine(m.ToString());
                m.Run();
                m.Speed_Up(30);
            }
        }
        static void BT2()
        {
            byte sl, chon, dem;
            dem = 0;
            Console.WriteLine("Nhập số lượng con vật = ");
            sl = byte.Parse(Console.ReadLine());
            ANIMAL[] dv = new ANIMAL[20];
            for (int i = 0; i < sl; i++)
            {
                Console.WriteLine("Chọn loại:(1.Gà,  2.Chó,  3.Mèo)");
                chon = byte.Parse(Console.ReadLine());
                switch (chon)
                {
                    case 1:
                        dv[i] = new Ga();
                        break;
                    case 2:
                        dv[i] = new Cho();
                        break;
                    case 3:
                        dv[i] = new Meo();
                        break;
                    default:
                        Console.WriteLine("Bạn nhập sai rồi ! Mời Nhập Lại ");
                        break;
                }

            }
            for (int i = 0; i < sl; i++)
            {
                Console.WriteLine(dv[i].ToString());
                dv[i].Keu();
                dv[i].thucan();
                if (dv[i] is Meo) dem++;
            }
            Console.WriteLine("Có {0} con mèo khi chọn", dem);
        }
        static void Main()
        {
            Console.OutputEncoding = Encoding.UTF8;
            BT1();
            BT2();
            Console.ReadKey();
        }
    }

}
