#include<iostream>
using namespace std;

// khai b�o c?u tr�c 1 c�i node trong c�y nh? ph�n t�m ki?m
struct node
{
	int data; // d? li?u ch?a trong 1 c�i node
	struct node *pLeft; // con tr? li�n k?t v?i c�i node b�n tr�i <=> c�y con tr�i
	struct node *pRight; // con tr? li�n k?t v?i c�i node b�n ph?i <=> c�y con ph?i
};
typedef struct node NODE;
typedef NODE* TREE;

// h�m kh?i t?o c�y nh? ph�n t�m ki?m
void KhoiTaoCay(TREE &t)
{
	t = NULL;
}

// h�m th�m 1 c�i ph?n t? v�o c�y
void ThemNodeVaoCay(TREE &t, int x)
{
	// n?u c�y r?ng
	if (t == NULL)
	{
		NODE *p = new NODE;
		p->data = x;
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;
	}
	else
	{
		// n?u ph?n t? th�m v�o m� nh? hon n�t g?c th� s? duy?t qua b�n tr�i
		if (x < t->data)
		{
			ThemNodeVaoCay(t->pLeft, x);
		}
		else if (x > t->data)
		{
			ThemNodeVaoCay(t->pRight, x);
		}
	}
}

// h�m xu?t ph?n t? trong c�y nh? ph�n t�m ki?m
void NLR(TREE t)
{
	if (t != NULL)
	{
		// x? l�
		cout << t->data << "  ";
		NLR(t->pLeft);
		NLR(t->pRight);
	}
}

// h�m ki?m tra s? nguy�n t?
bool KiemTraSoNguyenTo(int x)
{
	if (x < 2)
	{
		return false;
	}
	else
	{
		if (x == 2)
		{
			return true;
		}
		else
		{
			if (x % 2 == 0)
			{
				return false;
			}
			else
			{
				for (int i = 2; i < x; i++)
				{
					if (x % i == 0)
					{
						return false;
					}
				}
			}	
		}
	}
	return true;
}

// h�m d?m s? lu?ng s? nguy�n t?
void SoLuongSoNguyenTo(TREE t, int &dem)
{
	if (t != NULL)
	{
		// x? l�
		if (KiemTraSoNguyenTo(t->data) == true)
		{
			dem++;
		}
		// 2 c�i d�ng n�y c� t�c d?ng l� duy?t qua t?ng c�i node trong c�y
		SoLuongSoNguyenTo(t->pLeft, dem);
		SoLuongSoNguyenTo(t->pRight, dem);
	}
}

// h�m nh?p c�y nh? ph�n t�m ki?m
void Menu(TREE &t)
{
	int luachon;
	while(true)
	{
		system("cls");
		cout << "\n\n\t\t ============ MENU ============";
		cout << "\n1. Nhap phan tu";
		cout << "\n2. Duyet cay";
		cout << "\n3. Dem so luong so nguyen to";
		cout << "\n0. Thoat";
		cout << "\n\n\t\t =============  END  =============";

		cout << "\nNhap lua chon: ";
		cin >> luachon;

		if (luachon == 1)
		{
			int x;
			cout << "\nNhap phan tu: ";
			cin >> x;
			ThemNodeVaoCay(t, x);
		}
		else if (luachon == 2)
		{
			cout << "\n\t CAY NHI PHAN TIM KIEM\n";
			NLR(t);
			system("pause");
		}
		else if (luachon == 3)
		{
			int dem = 0;
			SoLuongSoNguyenTo(t, dem);
			cout << "\n\t SO LUONG SO NGUYEN TO: " << dem;
			
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
	TREE t;
	KhoiTaoCay(t);
	Menu(t);

	system("pause");
	return 0;
}
