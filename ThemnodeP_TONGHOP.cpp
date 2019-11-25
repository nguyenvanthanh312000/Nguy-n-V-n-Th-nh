#include<iostream>
using namespace std;



// ========== KHAI BÁO CẤU TRÚC 1 CÁI NODE ==========
struct node
{
	int data; // dữ liệu của node
	struct node *pNext; // con trỏ dùng để liên kết giữa các cái node với nhau
};
typedef struct node NODE;

// ========== KHAI BÁO CẤU TRÚC DANH SÁCH LIÊN KẾT ĐƠN =========

struct list
{
	NODE *pHead;
	NODE *pTail;
};
typedef struct list LIST;


// hàm khởi tạo danh sách liên kết đơn
void KhoiTaoDanhSach(LIST &l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}
// hàm khởi tạo 1 cái node để chuẩn bị thêm vào danh sách
NODE *KhoiTaoNode(int x)
{
	NODE *p = new NODE;
	if (p == NULL)
	{
		cout << "\nCap phat that bai !";
		return NULL;
	}
	p->data = x; // đưa dữ liệu của biến x vào data của cái Node p
	p->pNext = NULL; // khởi tạo node p nhưng node p chưa có liên kết đến node nào hết

	return p;
}

// hàm thêm 1 cái node vào đầu danh sách
void ThemDau(LIST &l, NODE *p)
{
	// nếu danh sách rỗng
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p; // node p thêm vào cũng chính là node đầu và node cuối
	}
	else
	{
		p->pNext = l.pHead; // cho con trỏ p trỏ đến pHead
		l.pHead = p; // cập nhật lại pHead là node p
	}
}

// hàm thêm 1 cái node vào cuối danh sách
void ThemCuoi(LIST &l, NODE *p)
{
	// nếu danh sách rỗng
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p; // node p thêm vào cũng chính là node đầu và node cuối
	}
	else
	{
		l.pTail->pNext = p; // cho con trỏ của pTail trỏ đến node p
		l.pTail = p; // cập nhật lại pTail chính là node p
	}
}

// hàm thêm node p sau node q <=> nếu node p bằng node q ?????
void ThemNode_p_SauNode_q(LIST &l, NODE *p)
{
	int x;
	cout << "\nNhap node q: ";
	cin >> x;
	NODE *q = KhoiTaoNode(x);

	// duyệt từ đầu danh sách để tìm node q cần thêm vào sau 
	for (NODE *k = l.pHead; k != NULL; k = k->pNext)
	{
		if (k->data == q->data)
		{
			NODE *g = KhoiTaoNode(p->data);
			g->pNext = k->pNext; // cho node p cần thêm vào sau node q trỏ đến node nằm sau node k <=> cập nhật mối liên kết
			k->pNext = g; // cho node q - cũng chính là node k trỏ đến node p
		}
	}
}

// hàm thêm node p trước node q <=> nếu node p bằng node q ?????
void ThemNode_p_TruocNode_q(LIST &l, NODE *p)
{
	int x;
	cout << "\nNhap node q: ";
	cin >> x;
	NODE *q = KhoiTaoNode(x);

	NODE *h = new NODE;
	// duyệt từ đầu danh sách để tìm node q cần thêm vào sau 
	for (NODE *k = l.pHead; k != NULL; k = k->pNext)
	{
		if (k->data == q->data)
		{
			NODE *g = KhoiTaoNode(p->data);
			g->pNext = k; // cho node p cần thêm vào sau node q trỏ đến node nằm sau node k <=> cập nhật mối liên kết
			h->pNext = g; // cho node q - cũng chính là node k trỏ đến node p
		}
		h = k;
	}
}

// hàm xóa đầu
void XoaDau(LIST &l)
{
	// nếu danh sách rỗng
	if (l.pHead == NULL)
	{
		return;
	}
	NODE *p = l.pHead; // node p là node sẽ xóa
	l.pHead = l.pHead->pNext;// cập nhật lại l.pHead là phần tử kế tiếp
	delete p;
}

// xóa cuối
void XoaCuoi(LIST &l)
{

	// nếu danh sách rỗng
	if (l.pHead == NULL)
	{
		return;
	}
	// trường hợp danh sách có phần tử
	if (l.pHead->pNext == NULL)
	{
		XoaDau(l);
		return;
	}
	// duyệt từ đầu danh sách đến thằng kế cuối
	for (NODE *k = l.pHead; k != NULL; k = k->pNext)
	{
		// phát hiện thằng kế cuối
		if (k->pNext == l.pTail)
		{
			delete l.pTail; // xóa đi phần tử cuối
			k->pNext = NULL; // cho con trỏ của node kế cuối trỏ đến vùng nhớ null
			l.pTail = k; // cập nhật lại l.pTail
			return;
		}
	}
}

// hàm xóa 1 node nằm sau node q trong danh sách
void XoaSauNode_q(LIST &l, NODE *q)
{
	// duyệt danh sách từ đầu đến cuối để tìm node q
	for (NODE *k = l.pHead; k != NULL; k = k->pNext)
	{
		// phát hiện node q
		if (k->data == q->data)
		{
			NODE *g = k->pNext; // node g chính là node nằm sau node k(nằm sau node q) <=> node mà ta sẽ xóa
			k->pNext = g->pNext; // cập nhật mối liên kết giữa node k(node q) với node sau node g 
			delete g; // xóa node nằm sau node q			
		}
	}
}

// hàm xuất danh sách liên kết đơn
void XuatDanhSach(LIST l)
{
	for (NODE *k = l.pHead; k != NULL; k = k->pNext)
	{
		cout << k->data << "  ";
	}
}

// hàm xóa 1 cái node có khóa k bất kì
void XoaNodeCoKhoaBatKy(LIST &l, int x)
{
	// nếu danh sách rỗng thì không làm gì hết
	if (l.pHead == NULL)
	{
		return;
	}
	// nếu node cần xóa nằm đầu danh sách
	if (l.pHead->data == x)
	{
		XoaDau(l);
		return;
	}
	// nếu node cần xóa nằm ở cuối danh sách
	if (l.pTail->data == x)
	{
		XoaCuoi(l);
		return;
	}

	NODE *g = new NODE; // node g là node trỏ đến node nằm trước node cần xóa: x
	// duyệt danh sách liên kết đơn để tìm
	for (NODE *k = l.pHead; k != NULL; k = k->pNext)
	{
		// phát hiện phần tử cần xóa
		if (k->data == x)
		{
			g->pNext = k->pNext; // cập nhật mối liên kết giữa node k với node sau node h
			delete k; // xóa node nằm sau node k	
			return;
		}
		g = k; // cho node g trỏ đến node k
	}

}

// hàm menu
void Menu(LIST &l)
{
	int luachon;
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t =========== MENU ===========";
		cout << "\n1. Them node vao danh sach";
		cout << "\n2. Xuat danh sach";
		cout << "\n3. Them node p vao sau node q";
		cout << "\n4. Them node p vao truoc node q";
		cout << "\n5. Xoa dau";
		cout << "\n6. Xoa cuoi";
		cout << "\n7. Xoa node sau node q";
		cout << "\n8. Xoa node co khoa k bat ky";
		cout << "\n0. Ket thuc";
		cout << "\n\n\t\t =========== END ===========";

		cout << "\nNhap lua chon: ";
		cin >> luachon;
		if (luachon == 1)
		{
			int x;
			cout << "\nNhap gia tri can them: ";
			cin >> x;
			NODE *p = KhoiTaoNode(x);
			ThemCuoi(l, p);
		}
		else if (luachon == 2)
		{
			cout << "\n\n\t\t DANH SACH LIEN KET DON \n";
			XuatDanhSach(l);
			system("pause");
		}
		else if (luachon == 3)
		{
			int x;
			cout << "\nNhap node q can them: ";
			cin >> x;
			NODE *q = KhoiTaoNode(x);
			ThemNode_p_SauNode_q(l, q);
		}
		else if (luachon == 4)
		{
			int x;
			cout << "\nNhap node q can them: ";
			cin >> x;
			NODE *q = KhoiTaoNode(x);
			ThemNode_p_TruocNode_q(l, q);
		}
		else if (luachon == 5)
		{
			XoaDau(l);
		}
		else if (luachon == 6)
		{
			XoaCuoi(l);
		}
		else if (luachon == 7)
		{
			int x;
			cout << "\nNhap node q: ";
			cin >> x;
			NODE *q = KhoiTaoNode(x);
			XoaSauNode_q(l, q);
		}
		else if (luachon == 8)
		{
			int x;
			cout << "\nNhap node can xoa: ";
			cin >> x;
			XoaNodeCoKhoaBatKy(l, x);
		}
		else
		{
			break;
		}
	}
}

int main()
{
	LIST l;
	KhoiTaoDanhSach(l);
	Menu(l);
	system("pause");
	return 0;
}
