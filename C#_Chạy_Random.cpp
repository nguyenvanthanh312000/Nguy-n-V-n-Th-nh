static void testRandom()
        {
            Random rd = new Random();
            int x = rd.Next(11);
            Console.WriteLine("Số được tạo ngẫu nhiên là {0}", x);
            Console.ReadLine();
        }
        static void Main(string[] args)
        {
            Console.OutputEncoding = Encoding.UTF8;
            testRandom();
        }
