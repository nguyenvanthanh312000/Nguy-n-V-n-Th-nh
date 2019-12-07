#include<iostream>
using namespace std;

// khai báo c?u trúc 1 cái node trong cây nh? phân tìm ki?m
struct node
{
	int data; // d? li?u ch?a trong 1 cái node
	struct node *pLeft; // con tr? liên k?t v?i cái node bên trái <=> cây con trái
	struct node *pRight; // con tr? liên k?t v?i cái node bên ph?i <=> cây con ph?i
};
typedef struct node NODE;
typedef NODE* TREE;

// hàm kh?i t?o cây nh? phân tìm ki?m
void KhoiTaoCay(TREE &t)
{
	t = NULL;
}

// hàm thêm 1 cái ph?n t? vào cây
void ThemNodeVaoCay(TREE &t, int x)
{
	// n?u cây r?ng
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
		// n?u ph?n t? thêm vào mà nh? hon nút g?c thì s? duy?t qua bên trái
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

// hàm xu?t ph?n t? trong cây nh? phân tìm ki?m
void NLR(TREE t)
{
	if (t != NULL)
	{
		// x? lí
		cout << t->data << "  ";
		NLR(t->pLeft);
		NLR(t->pRight);
	}
}

// hàm ki?m tra s? nguyên t?
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

// hàm d?m s? lu?ng s? nguyên t?
void SoLuongSoNguyenTo(TREE t, int &dem)
{
	if (t != NULL)
	{
		// x? lí
		if (KiemTraSoNguyenTo(t->data) == true)
		{
			dem++;
		}
		// 2 cái dòng này có tác d?ng là duy?t qua t?ng cái node trong cây
		SoLuongSoNguyenTo(t->pLeft, dem);
		SoLuongSoNguyenTo(t->pRight, dem);
	}
}

// hàm nh?p cây nh? phân tìm ki?m
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
