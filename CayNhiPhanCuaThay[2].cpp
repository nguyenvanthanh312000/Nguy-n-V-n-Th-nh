#include <stdio.h>

struct nut {
	int gtri;
	nut *left,*right;
};

typedef nut Node;
Node *goc,*goc1;
//-----------------------------------------------------------------------------------
void khoitao(Node *&goc)
{
	goc = NULL;
}
//-----------------------------------------------------------------------------------
void mocnut(Node *&goc, int x)
{
	if(goc == NULL)
	{
		goc = new Node;
		goc->gtri = x;
		goc->left = NULL;
		goc->right = NULL;
	}
	else if(goc->gtri >= x)
		mocnut(goc->left,x);
	else
		mocnut(goc->right,x);
}
//-----------------------------------------------------------------------------------
void taocay(Node *&goc)
{
	int tam;
	do
	{
		printf("\n Nhap 1 so nguyen,0 : dung ");
		scanf("%d",&tam);
		if(tam != 0)
			mocnut(goc,tam);
	}while(tam!=0);
}
//-----------------------------------------------------------------------------------
void duyetLNR(Node *goc) // tham tri
{
	if(goc != NULL)
	{
		duyetLNR(goc->left);
		printf("%3d",goc->gtri);
		duyetLNR(goc->right);
	}	
}
//-----------------------------------------------------------------------------------
int demla(Node *goc)
{
	if(goc == NULL)
		return 0;
	else
		if((goc->left == NULL) && (goc->right == NULL))
			return 1;
		else
			return demla(goc->left)+demla(goc->right);	
}
//-----------------------------------------------------------------------------------
int demlachan(Node *goc)
{
	if(goc == NULL)
		return 0;
	else
		if((goc->left == NULL) && (goc->right == NULL))
			if(goc->gtri % 2 == 0) return 1; // neu no nut la va gtri no chan thi return 1
			else return 0; 
		else 
			return demlachan(goc->left)+demlachan(goc->right);	
}
//-----------------------------------------------------------------------------------
int demlachan1(Node *goc)
{
	if(goc == NULL)
		return 0;
	else
		if((goc->left == NULL) && (goc->right == NULL) &&( goc->gtri % 2 == 0)) // neu no nut la va gtri no chan thi return 1 
			return 1; 
		else 
			return demlachan(goc->left)+demlachan(goc->right);	
}
//-----------------------------------------------------------------------------------
int tongcacnut(Node *goc)
{
	if(goc == NULL)
		return 0;
	else if ((goc->left == NULL) && (goc->right == NULL))
		return goc->gtri;
	else
		return goc->gtri+tongcacnut(goc->left)+tongcacnut(goc->right);
}
//-----------------------------------------------------------------------------------
int tongnutla(Node *goc)
{
	if(goc == NULL)
		return 0;
	else if ((goc->left == NULL) && (goc->right == NULL))
		return goc->gtri;
	else
		return tongnutla(goc->left)+tongnutla(goc->right);
}
//-----------------------------------------------------------------------------------
int max(int a,int b)
{
	if(a >= b)
		return a;
	else
		return b;
}

int chieucao(Node *goc)
{
	if(goc == NULL)
		return 0;
	else
		return 1+max(chieucao(goc->left),chieucao(goc->right));
}
//-----------------------------------------------------------------------------------
int demthp(Node *goc)
{
	if(goc == NULL)
		return 0;
	else if(chieucao(goc->left) > chieucao(goc->right))
		return 1+demthp(goc->left)+demthp(goc->right);
	else
		return demthp(goc->left)+demthp(goc->right);
}
//-----------------------------------------------------------------------------------
void inmuci(Node *goc, int i,int muc)
{
	if(goc != NULL)
		if(muc == i)
			printf("%3d",goc->gtri);
		else 
		{
			// chuyen qua muc tiep theo (cac cay con cua no)
			// cha la nut i -> nut con la i + 1
			inmuci(goc->left,i,muc+1);
			inmuci(goc->right,i,muc+1);
		}
}
//-----------------------------------------------------------------------------------
int tongmuci(Node *goc, int i, int muc)
{
	if(goc == NULL)
		return 0;
	else if(muc == i)
		return goc->gtri;
	else
		return tongmuci(goc->left,i,muc+1) + tongmuci(goc->right,i,muc+1);
}
//-----------------------------------------------------------------------------------
void saochep(Node *goc,Node *&goc1)
{
	if(goc == NULL)
		goc1 = NULL;
	else
	{
		goc1 = new Node;
		goc1->gtri = goc->gtri;
		saochep(goc->left,goc1->left);
		saochep(goc->right,goc1->right);
	}
}
//-----------------------------------------------------------------------------------
void hoandoi(Node *&goc1)
{
	Node *tam;
		if(goc1 != NULL)
		{
			tam = goc1->left;
			goc1->left = goc1->right;
			goc1->right = tam;
				hoandoi(goc1->left);
				hoandoi(goc1->right);
		}
}
//-----------------------------------------------------------------------------------
int main()
{
	khoitao(goc);khoitao(goc1);
	taocay(goc);
//-----------------------------------------------------------------------------------
	printf("\n Duyet LNR \n");
	duyetLNR(goc);
//-----------------------------------------------------------------------------------
	printf("\n So nut la: %d",demla(goc));
//-----------------------------------------------------------------------------------
	printf("\n So nut la chan: %d",demlachan(goc));
//-----------------------------------------------------------------------------------
	printf("\n tong cac nut : %d",tongcacnut(goc));
//-----------------------------------------------------------------------------------
	printf("\n tong nut la: %d",tongnutla(goc));
//-----------------------------------------------------------------------------------
	printf("\n chieu cao cua cay: %d",chieucao(goc));	
//-----------------------------------------------------------------------------------
	printf("\n dem so nut chieu cao cay con trai > ch.cao cay con phai : %d",demthp(goc));	
//-----------------------------------------------------------------------------------
	int i;
	printf("\n Nhap muc can in: ");
	scanf("%d",&i);
	printf("\n in muc i: ");
	inmuci(goc,i,1);
//-----------------------------------------------------------------------------------
	printf("\n Tong cac nut o muc i: %d",tongmuci(goc,i,1));
//-----------------------------------------------------------------------------------	
	saochep(goc,goc1);
	printf("\n Cay 1 \n");
	duyetLNR(goc);
	printf("\n Cay 2 \n");
	duyetLNR(goc1);
//-----------------------------------------------------------------------------------
	printf("\n Cay goc 1 sau hoan doi \n");
	hoandoi(goc1);
	duyetLNR(goc1);
//-----------------------------------------------------------------------------------
return 0;
}
