static void choi()
        {
            Console.OutputEncoding = Encoding.UTF8;
            Random rd = new Random();
            int soCuamay = rd.Next(501);
            int soCuanguoi;
            int soLandoan = 0;
            Console.WriteLine("Máy đã ra 1 số trong đoạn từ 0...500 , mời bạn đoán  ");
            while (true)
            {
                soCuanguoi = int.Parse(Console.ReadLine());
                soLandoan++;
                Console.WriteLine("Bạn đoán lần thứ {0}", soLandoan);
                if (soCuanguoi == soCuamay)
                {
                    Console.WriteLine("Bạn đã nhập đúng xin chúc mừng ! ");
                    break;
                }
                if (soCuanguoi < soCuamay)
                {
                    Console.WriteLine("Số của người < Số của máy ");
                }
                else
                {
                    Console.WriteLine("Số của người > Số của máy ");
                }
                if (soLandoan == 7)
                {
                    Console.WriteLine("Game OVer , Bạn có chơi tiếp ko ?");
                    break;
                }
            }
        }
        static void Main(string[] args)
        {
            while(true)
            {
                choi();
                Console.WriteLine("Chơi nữa không  ? (Có / Không ) :");
                string s = Console.ReadLine();
                if(s == không )
                    break;
            }
            Console.ReadLine();
        }
