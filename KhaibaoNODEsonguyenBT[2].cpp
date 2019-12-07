#include<iostream>
using namespace std;



// ========== KHAI BÁO C?U TRÚC 1 CÁI NODE ==========
struct node
{
	int data; // d? li?u c?a node
	struct node *pNext; // con tr? dùng d? liên k?t gi?a các cái node v?i nhau
};
typedef struct node NODE;

// ========== KHAI BÁO C?U TRÚC DANH SÁCH LIÊN K?T ÐON =========

struct list
{
	NODE *pHead;
	NODE *pTail;
};
typedef struct list LIST;


// hàm kh?i t?o danh sách liên k?t don
void KhoiTaoDanhSach(LIST &l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}
// hàm kh?i t?o 1 cái node d? chu?n b? thêm vào danh sách
NODE *KhoiTaoNode(int x)
{
	NODE *p = new NODE;
	if (p == NULL)
	{
		cout << "\nCap phat that bai !";
		return NULL;
	}
	p->data = x; // dua d? li?u c?a bi?n x vào data c?a cái Node p
	p->pNext = NULL; // kh?i t?o node p nhung node p chua có liên k?t d?n node nào h?t

	return p;
}

// hàm thêm 1 cái node vào d?u danh sách
void ThemDau(LIST &l, NODE *p)
{
	// n?u danh sách r?ng
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p; // node p thêm vào cung chính là node d?u và node cu?i
	}
	else
	{
		p->pNext = l.pHead; // cho con tr? p tr? d?n pHead
		l.pHead = p; // c?p nh?t l?i pHead là node p
	}
}

// hàm thêm 1 cái node vào cu?i danh sách
void ThemCuoi(LIST &l, NODE *p)
{
	// n?u danh sách r?ng
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p; // node p thêm vào cung chính là node d?u và node cu?i
	}
	else
	{
		l.pTail->pNext = p; // cho con tr? c?a pTail tr? d?n node p
		l.pTail = p; // c?p nh?t l?i pTail chính là node p
	}
}

// hàm thêm node p sau node q <=> n?u node p b?ng node q ?????
void ThemNode_p_SauNode_q(LIST &l, NODE *p)
{
	int x;
	cout << "\nNhap node q: ";
	cin >> x;
	NODE *q = KhoiTaoNode(x);

	// duy?t t? d?u danh sách d? tìm node q c?n thêm vào sau 
	for (NODE *k = l.pHead; k != NULL; k = k->pNext)
	{
		if (k->data == q->data)
		{
			NODE *g = KhoiTaoNode(p->data);
			g->pNext = k->pNext; // cho node p c?n thêm vào sau node q tr? d?n node n?m sau node k <=> c?p nh?t m?i liên k?t
			k->pNext = g; // cho node q - cung chính là node k tr? d?n node p
		}
	}
}

// hàm thêm node p tru?c node q <=> n?u node p b?ng node q ?????
void ThemNode_p_TruocNode_q(LIST &l, NODE *p)
{
	int x;
	cout << "\nNhap node q: ";
	cin >> x;
	NODE *q = KhoiTaoNode(x);

	NODE *h = new NODE;
	// duy?t t? d?u danh sách d? tìm node q c?n thêm vào sau 
	for (NODE *k = l.pHead; k != NULL; k = k->pNext)
	{
		if (k->data == q->data)
		{
			NODE *g = KhoiTaoNode(p->data);
			g->pNext = k; // cho node p c?n thêm vào sau node q tr? d?n node n?m sau node k <=> c?p nh?t m?i liên k?t
			h->pNext = g; // cho node q - cung chính là node k tr? d?n node p
		}
		h = k;
	}
}

// hàm xóa d?u
void XoaDau(LIST &l)
{
	// n?u danh sách r?ng
	if (l.pHead == NULL)
	{
		return;
	}
	NODE *p = l.pHead; // node p là node s? xóa
	l.pHead = l.pHead->pNext;// c?p nh?t l?i l.pHead là ph?n t? k? ti?p
	delete p;
}

// xóa cu?i
void XoaCuoi(LIST &l)
{

	// n?u danh sách r?ng
	if (l.pHead == NULL)
	{
		return;
	}
	// tru?ng h?p danh sách có ph?n t?
	if (l.pHead->pNext == NULL)
	{
		XoaDau(l);
		return;
	}
	// duy?t t? d?u danh sách d?n th?ng k? cu?i
	for (NODE *k = l.pHead; k != NULL; k = k->pNext)
	{
		// phát hi?n th?ng k? cu?i
		if (k->pNext == l.pTail)
		{
			delete l.pTail; // xóa di ph?n t? cu?i
			k->pNext = NULL; // cho con tr? c?a node k? cu?i tr? d?n vùng nh? null
			l.pTail = k; // c?p nh?t l?i l.pTail
			return;
		}
	}
}

// hàm xóa 1 node n?m sau node q trong danh sách
void XoaSauNode_q(LIST &l, NODE *q)
{
	// duy?t danh sách t? d?u d?n cu?i d? tìm node q
	for (NODE *k = l.pHead; k != NULL; k = k->pNext)
	{
		// phát hi?n node q
		if (k->data == q->data)
		{
			NODE *g = k->pNext; // node g chính là node n?m sau node k(n?m sau node q) <=> node mà ta s? xóa
			k->pNext = g->pNext; // c?p nh?t m?i liên k?t gi?a node k(node q) v?i node sau node g 
			delete g; // xóa node n?m sau node q			
		}
	}
}

// hàm xu?t danh sách liên k?t don
void XuatDanhSach(LIST l)
{
	for (NODE *k = l.pHead; k != NULL; k = k->pNext)
	{
		cout << k->data << "  ";
	}
}

// hàm xóa 1 cái node có khóa k b?t kì
void XoaNodeCoKhoaBatKy(LIST &l, int x)
{
	// n?u danh sách r?ng thì không làm gì h?t
	if (l.pHead == NULL)
	{
		return;
	}
	// n?u node c?n xóa n?m d?u danh sách
	if (l.pHead->data == x)
	{
		XoaDau(l);
		return;
	}
	// n?u node c?n xóa n?m ? cu?i danh sách
	if (l.pTail->data == x)
	{
		XoaCuoi(l);
		return;
	}

	NODE *g = new NODE; // node g là node tr? d?n node n?m tru?c node c?n xóa: x
	// duy?t danh sách liên k?t don d? tìm
	for (NODE *k = l.pHead; k != NULL; k = k->pNext)
	{
		// phát hi?n ph?n t? c?n xóa
		if (k->data == x)
		{
			g->pNext = k->pNext; // c?p nh?t m?i liên k?t gi?a node k v?i node sau node h
			delete k; // xóa node n?m sau node k	
			return;
		}
		g = k; // cho node g tr? d?n node k
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
