#include<iostream>
using namespace std;

struct node
{
	int data; // d? li?u c?a node
	struct node *pNext; // con tr? dùng d? liên k?t gi?a các cái node v?i nhau
};
typedef struct node NODE;

NODE *KhoiTaoNode(int x)
{
	NODE *p = new NODE;
	if (p == NULL)
	{
		return NULL;
	}
	p->data = x;
	p->pNext = NULL;
	return p;
}

void ThemDau(NODE *&pHead, NODE *p)
{
	// danh sach rong
	if(pHead == NULL)
	{
		pHead = p;
	}
	else
	{
		p->pNext = pHead;
		pHead = p;
	}
}

void XuatDanhSach(NODE *pHead)
{
	for(NODE *k = pHead; k !=NULL;k=k->pNext)
	{
		cout << k->data << " ";
	}
}

void HamGiaiPhongVungNho(NODE *pHead)
{
	NODE *k = NULL;
	while (pHead != NULL)
	{
		k = pHead;
		pHead = pHead ->pNext;
		delete k;
	}
}

// ham sap xep danh sach giam dan
void SapXepGiamDan(NODE *&pHead)
{
	for(NODE *k = pHead ; k != NULL; k = k ->pNext)
	{
		for(NODE *h = k->pNext; h != NULL; h = h ->pNext)
		{
			if(k->data < h->data)
			{
				int tam = k->data;
				k->data = h->data;
				h->data = tam;
			}
		}
	}
}

void XoaSau_Node_p(NODE *&pHead , int x)
{
	if(pHead == NULL)
	{
		return ;
	}
	else
	{
		NODE *g = NULL;
		for(NODE *k = pHead ; k != NULL; k = k ->pNext)
		{
			if(k->data == x)
			{
				g->pNext = k->pNext;
				delete k;
				break;
			}
			g = k;
		}
	}
}

void Menu(NODE *&pHead)
{
	int luachon;
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t =========== MENU ===========";
		cout << "\n1. Them node vao dau danh sach";
		cout << "\n2. Xuat danh sach";
		cout << "\n3. Sap xep danh sach giam dan";
		cout << "\n4. Xoa cac phan tu co khoa k bat ky";
		
		cout << "\nNhap lua chon: ";
		cin >> luachon;
		if (luachon == 1)
		{
			int x;
			cout << "\nNhap gia tri can them: ";
			cin >> x;
			NODE *p = KhoiTaoNode(x);
			ThemDau(pHead, p);
		}
		else if (luachon == 2)
		{
			cout << "\n\n\t\t DANH SACH LIEN KET DON \n";
			XuatDanhSach(pHead);
			system("pause");
		}
		else if (luachon == 3)
		{
			SapXepGiamDan(pHead);
		}
		else if (luachon == 4)
		{
			int k;
			cout << "\n\n\t\t Nhap vao so can muon xoa : \n";
			cin >> k;
			XoaSau_Node_p(pHead, k);
			system("pause");
		}
		else
		{
			break;
		}
	}
}

int main()
{
	NODE *pHead = NULL;
	Menu(pHead);
	system("pause");
	return 0;
}
