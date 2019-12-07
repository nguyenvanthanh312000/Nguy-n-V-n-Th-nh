#include<iostream>
using namespace std;

struct node
{
	int data; // d? li?u c?a node ==> d? li?u mà node s? luu tr?
	struct node *pLeft; // node liên k?t bên trái c?a cây <=> cây con trái
	struct node *pRight; // node liên k?t bên ph?i c?a cây <=> cây con ph?i
};
typedef struct node NODE;
typedef NODE* TREE;

void KhoiTaoCay(TREE &t)
{
	t = NULL;
}
void ThemNodeVaoCay(TREE &t, int x)
{
	// n?u cây r?ng
	if (t == NULL)
	{
		NODE *p = new NODE; // kh?i t?o 1 cái node d? thêm vào cây
		p->data = x;// thêm d? li?u x vào data
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;// node p chính là node g?c <=> x chính là node g?c
	}
	else // cây có t?n t?i ph?n t?
 	{
		// n?u ph?n t? thêm vào mà nh? hon node g?c ==> thêm nó vào bên trái
		if (t->data > x)
		{
			ThemNodeVaoCay(t->pLeft, x); // duy?t qua trái d? thêm ph?n t? x
		}
		else if (t->data < x) // n?u ph?n t? thêm vào mà l?n hon node g?c ==> thêm nó vào bên ph?i
		{
			ThemNodeVaoCay(t->pRight, x); // duy?t qua ph?i d? thêm ph?n t? x
		}
	}
}

void Duyet_NLR(TREE t)
{ 
	// n?u cây còn ph?n t? thì ti?p t?c duy?t
	if (t != NULL)
	{
		cout << t->data << " "; // xu?t d? li?u trong node
		Duyet_NLR(t->pLeft); // duy?t qua trái
		Duyet_NLR(t->pRight); // duy?t qua ph?i
	}
}

void Duyet_NRL(TREE t)
{
	// n?u cây còn ph?n t? thì ti?p t?c duy?t
	if (t != NULL)
	{
		cout << t->data << " "; // xu?t d? li?u trong node
		Duyet_NRL(t->pRight); // duy?t qua ph?i 
		Duyet_NRL(t->pLeft); // duy?t qua trái
	}
}

void Duyet_LNR(TREE t)
{
	// n?u cây còn ph?n t? thì ti?p t?c duy?t
	if (t != NULL)
	{
		Duyet_LNR(t->pLeft); // duy?t qua trái
		cout << t->data << "  "; // xu?t giá tr? c?a node
		Duyet_LNR(t->pRight); // duy?t qua ph?i
	}
}

void Duyet_RNL(TREE t)
{
	// n?u cây còn ph?n t? thì ti?p t?c duy?t
	if (t != NULL)
	{
		Duyet_RNL(t->pRight); // duy?t qua ph?i
		cout << t->data << "  "; // xu?t giá tr? c?a node
		Duyet_RNL(t->pLeft); // duy?t qua ph?i
	}
}

void Duyet_LRN(TREE t)
{
	// n?u cây còn ph?n t? thì ti?p t?c duy?t
	if (t != NULL)
	{
		Duyet_LRN(t->pLeft); // duy?t qua trái
		Duyet_LRN(t->pRight); // duy?t qua ph?i
		cout << t->data << "  "; // xu?t giá tr? c?a node
	}
}

void Duyet_RLN(TREE t)
{
	// n?u cây còn ph?n t? thì ti?p t?c duy?t
	if (t != NULL)
	{
		Duyet_RLN(t->pRight); // duy?t qua ph?i
		Duyet_RLN(t->pLeft); // duy?t qua trái
		cout << t->data << "  "; // xu?t giá tr? c?a node
	}
}

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

int tongcacnut(TREE t)
{
	if(t == NULL)
		return 0;
	else if(t->pRight==NULL || t->pLeft==NULL)
		return 0;
	else if (t->pRight->data==2*t->pLeft->data)
		return t->data+tongcacnut(t->pRight)+tongcacnut(t->pLeft);
	else
		return tongcacnut(t->pRight)+tongcacnut(t->pLeft);
}

int demSoNut(TREE t) {
	if(t ==NULL)
	return 0;
	return 1 + demSoNut(t->pLeft) + demSoNut(t->pRight);
}
int tongNut(TREE t) {
	if(t == NULL)
		return 0;
	else if((t->pLeft == NULL && t->pRight == NULL))
		return t->data;
	else
		return t->data + tongNut(t->pLeft) + tongNut(t->pRight);
}

int dem(TREE t)
{	// dem so node trong cay nhi phan.
	if( t == NULL ) return 0;
	else return( dem(t->pRight) + dem(t->pLeft) ) +1;
}
// hàm nh?p d? li?u
void Menu(TREE &t)
{
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t =========== MENU ===========";
		cout << "\n1. Nhap du lieu";
		cout << "\n2. Duyet cay NLR";
		cout << "\n3. Duyet cay NRL";
		cout << "\n4. Duyet cay LNR";
		cout << "\n5. Duyet cay RNL";
		cout << "\n6. Duyet cay LRN";
		cout << "\n7. Duyet cay RLN";
		cout << "\n8. Dem so nut la";
		cout << "\n9. Tong so nut phai == 2*trai";
		cout << "\n10. Dem so nut la";
		cout << "\n11. Tong so nut la";
		cout << "\n12. demla";
		cout << "\n0. Ket thuc";
		cout << "\n\n\t\t ============================";

		int luachon;

		cout << "\nNhap lua chon: ";
		cin >> luachon;
		if (luachon < 0 || luachon > 12)
		{
			cout << "\nLua chon khong hop le";
			system("pause");
		}
		else if (luachon == 1)
		{
			int x;
			cout << "\nNhap so nguyen x: ";
			cin >> x;
			ThemNodeVaoCay(t, x);
		}
		else if (luachon == 2)
		{
			cout << "\n\t\t DUYET CAY THEO NLR\n";
			Duyet_NLR(t);
			system("pause");
		}
		else if (luachon == 3)
		{
			cout << "\n\t\t DUYET CAY THEO NRL\n";
			Duyet_NRL(t);
			system("pause");
		}
		else if (luachon == 4)
		{
			cout << "\n\t\t DUYET CAY THEO LNR\n";
			Duyet_LNR(t);
			system("pause");
		}
		else if (luachon == 5)
		{
			cout << "\n\t\t DUYET CAY THEO RNL\n";
			Duyet_RNL(t);
			system("pause");
		}
		else if (luachon == 6)
		{
			cout << "\n\t\t DUYET CAY THEO LRN\n";
			Duyet_LRN(t);
			system("pause");
		}
		else if (luachon == 7)
		{
			cout << "\n\t\t DUYET CAY THEO RLN\n";
			Duyet_RLN(t);
			system("pause");
		}
		else if (luachon==8)
		{
			cout << "\n\t\t Dem so nut la ";
			Node_La(t);
			system("pause");
		}
		else if (luachon==9)
		{
			cout << "\n\t\t Dem so tong nut la ";
			tongcacnut(t);
			system("pause");
		}
		
		else if (luachon==10)
		{
			cout << "\n\t\t Dem so nut ";
			demSoNut(t);
			system("pause");
		}
		else if (luachon==11)
		{
			cout << "\n\t\t Tong So Nut ";
			tongNut(t);
			system("pause");
		}
		else if (luachon==12)
		{
			cout << "\n\t\t DEM LA ";
			dem(t);
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
