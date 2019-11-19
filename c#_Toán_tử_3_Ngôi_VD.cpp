double diem;
            Console.WriteLine("Xin mời bạn nhập vào điểm của bạn là : ");
            diem = double.Parse(Console.ReadLine());

            string ketqua = diem >= 9 ? "Xuất sắc" : diem >= 8 ? "Giỏi" : diem >= 6.5 ? "Khá" : diem >= 5 ? "Yếu" : diem < 5 ? "Kém";
            Console.WriteLine("Điểm của bạn là {0} ==> {1}", diem, ketqua);
------------------------------
Nhập toán ( + - * / )


Console.OutputEncoding = Encoding.UTF8;
            int a, b;
            char kt;
            Console.Write("Mời bạn nhập vào a : ");
            a = int.Parse(Console.ReadLine());
            Console.Write("Mời bạn nhập vào b : ");
            b = int.Parse(Console.ReadLine());
            Console.Write("Các phép toán : (+ - * / ) :");
            kt = char.Parse(Console.ReadLine());

            switch(kt)
            {
                case '+':
                    Console.WriteLine("{0} + {1} = {2}", a, b, a + b);
                    break;
                case '-':
                    Console.WriteLine("{0} - {1} = {2}", a, b, a - b);
                    break;
                case '*':
                    Console.WriteLine("{0} * {1} = {2}", a, b, a * b);
                    break;
                case '/':
                    Console.WriteLine("{0} / {1} = {2}", a, b, a / b);
                    break;
            }
