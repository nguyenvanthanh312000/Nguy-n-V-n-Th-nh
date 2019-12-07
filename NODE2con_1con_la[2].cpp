#include<iostream>
using namespace std;

// nh?p vào cây nh? phân tìm ki?m các s? nguyên

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

// n?u node có t?n t?i trong cây thì tr? v? cái node dó - còn không t?n t?i thì tr? v? NULL
NODE* TimKiem(TREE t, int x)
{ 
	// n?u cây r?ng
	if (t == NULL)
	{
		return NULL;
	}
	else
	{
		// n?u ph?n t? c?n tìm ki?m mà nh? hon node g?c thì duy?t(d? quy) sang bên trái d? tìm
		if (x < t->data)
		{
			TimKiem(t->pLeft, x);
		}
		else if (x > t->data) // duy?t sang bên ph?i
		{
			TimKiem(t->pRight, x);
		}
		else // <=> t->data == x
		{
			return t; // tr? v? node c?n tìm ki?m
		}
	}

}


// xu?t các node có 2 con
void Node_Co_2_Con(TREE t)
{
	if (t != NULL)
	{
		// x? lí
		if (t->pLeft != NULL && t->pRight != NULL) // con trái và con ph?i có t?n t?i ph?n t?
		{
			cout << t->data << "  ";
		}
		Node_Co_2_Con(t->pLeft); // duy?t sang cây con trái c?a node hi?n t?i
		Node_Co_2_Con(t->pRight); // duy?t sang cây con ph?i c?a node hi?n t?i
	}
}
// xu?t các node có 1 con
void Node_Co_1_Con(TREE t)
{
	if (t != NULL)
	{
		// x? lí
		if ((t->pLeft != NULL && t->pRight == NULL) || (t->pLeft == NULL && t->pRight != NULL))
		{
			cout << t->data << "  ";
		}
		Node_Co_1_Con(t->pLeft); // duy?t sang cây con trái c?a node hi?n t?i
		Node_Co_1_Con(t->pRight); // duy?t sang cây con ph?i c?a node hi?n t?i
	}
}

// xu?t các node lá
void Node_La(TREE t)
{
	if (t != NULL)
	{
		// x? lí
		if (t->pLeft == NULL && t->pRight == NULL)
		{
			cout << t->data << "  ";
		}
		Node_La(t->pLeft); // duy?t sang cây con trái c?a node hi?n t?i
		Node_La(t->pRight); // duy?t sang cây con ph?i c?a node hi?n t?i
	}
}
// CÁCH 1: TÌM MAX
//int MAX = INT_MIN; // gán cho bi?n MAX là giá tr? nh? nh?t c?a ki?u integer
//// hàm tìm ph?n t? l?n nh?t trong cây
//void TimMax(TREE t)
//{
//	if (t != NULL)
//	{
//		// x? lí
//		if (MAX < t->data)
//		{
//			MAX = t->data; // c?p nh?t l?i giá tr? cho bi?n MAX
//		}
//		TimMax(t->pLeft);
//		TimMax(t->pRight);
//	}
//}

// CÁCH 2: TÌM MAX1
int TimMax(TREE t)
{
	//// n?u node cha mà không t?n t?i cây con trái và cây con ph?i
	//if (t->pLeft == NULL && t->pRight == NULL)
	//{
	//	return t->data;
	//}
	//int max = t->data; // gán giá tr? bi?n max chính là data c?a node cha 
	//// n?u node cha có t?n t?i cây con trái
	//if (t->pLeft != NULL)
	//{
	//	int left = TimMax(t->pLeft); // left là bi?n s? gi? giá tr? c?a cái node ngoài cùng nh?t bên trái c?a node cha
	//	if (max < left)
	//	{
	//		max = left;
	//	}
	//}
	//// n?u node cha có t?n t?i cây con ph?i
	//if (t->pRight != NULL)
	//{
	//	int right = TimMax(t->pRight); // right là bi?n s? gi? giá tr? c?a cái node ngoài cùng nh?t bên ph?i c?a node cha
	//	if (max < right)
	//	{
	//		max = right;
	//	}
	//}
	//return max; // tr? v? giá tr? l?n nh?t c?a cây nh? phân tìm ki?m

	// CÁCH T?I UU NH?T
	// n?u node cha mà không t?n cây con ph?i - thì node cha này chính là node ngoài cùng nh?t c?a cây con ph?i - cung chính là node có giá tr? l?n nh?t
	if (t->pRight == NULL)
	{
		return t->data;
	}
	return TimMax(t->pRight); // duy?t d?n node cu?i cùng nh?t bên cây con ph?i ==> d? tìm giá tr? l?n nh?t
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
		cout << "\n3. Tim kiem phan tu trong cay";
		cout << "\n4. Node co 2 con";
		cout << "\n5. Node co 1 con";
		cout << "\n6. Node la";
		cout << "\n7. Tim Max";
		cout << "\n0. Thoat";
		cout << "\n\n\t\t =============  END  =============";

		cout << "\nNhap lua chon: ";
		cin >> luachon;

		if (luachon == 1)
		{
			int x;
			cout << "\nNhap gia tri: ";
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
			int x;
			cout << "\nNhap phan tu can tim kiem: ";
			cin >> x;
			NODE *p = TimKiem(t, x);
			if (p == NULL)
			{
				cout << "\nPhan tu " << x << " khong ton tai trong cay";
			}
			else
			{
				cout << "\nPhan tu " << x << " co ton tai trong cay";
			}
			system("pause");
		}
		else if (luachon == 4)
		{
			cout << "\n\t NODE CO 2 CON: ";
			Node_Co_2_Con(t);
			system("pause");
		}
		else if (luachon == 5)
		{
			cout << "\n\t NODE CO 1 CON: ";
			Node_Co_1_Con(t);
			system("pause");
		}
		else if (luachon == 6)
		{
			cout << "\n\t NODE LA: ";
			Node_La(t);
			system("pause");
		}
		else if (luachon == 7)
		{
			// CÁCH 1:
			/*TimMax(t);
			cout << "\nMAX: " << MAX;*/

			// CÁCH 2:
			cout << "\nMAX: " << TimMax(t);
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
