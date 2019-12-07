#include <stdio.h>

struct nut
{
	int gtri;
	nut *left, *right;
};

typedef nut Node;
Node *goc, *goc1;

void khoitao (Node *&goc)
{
	goc=NULL;
}

void mocnut(Node *&goc, int x)
{
	if(goc==NULL)
	{
		goc=new Node;
		goc->gtri=x;
		goc->left=NULL;
		goc->right=NULL;
	}
	else
    	if(goc->gtri>=x)
	       mocnut(goc->left,x);
	    else
	      mocnut(goc->right,x);
}

void taocay(Node *&goc)
{
	int tam;
	do
	{
		printf("\n nhap 1 so nguyen, 0:dung ");
		scanf("%d",&tam);
		if (tam!=0)   mocnut(goc,tam);
	}while (tam!=0);
}

void duyetLNR(Node *goc)
{
	if(goc!=NULL)
	{
		duyetLNR(goc->left);
		printf("%3d",goc->gtri);
		duyetLNR(goc->right);
	}
}

int demnut(Node *goc)
{
	if (goc==NULL)   return 0;
	else
	   return 1+demnut(goc->left)+demnut(goc->right);
}

int tongnut(Node *goc)
{
	if(goc==NULL)    return 0;
	else
	 return goc->gtri+tongnut(goc->left)+tongnut(goc->right);	
}

int demla(Node *goc)
{
	if(goc==NULL)  return 0;
	else
	  if ((goc->left==NULL)&&(goc->right==NULL))
	  return 1;
	  else
	  return demla(goc->left)+demla(goc->right);
}

int tonglachan(Node *goc)
{
	if(goc==NULL)  return 0;
	else
	  if((goc->left==NULL)&&(goc->right==NULL))
	    if(goc->gtri%2==0)
	       return goc->gtri;
	    else  
		    return 0;
	  else
	   return tonglachan(goc->left)+tonglachan(goc->right);	   
}
//in ra cac nut la //int ko phair tra ve gtri nen dung void
void inla(Node *goc)
{
	if(goc!=NULL)
	  if((goc->left==NULL)&&(goc->right==NULL))
	    printf("%3d",goc->gtri);
	  else
	  { 
	   inla(goc->left);
	   inla(goc->right);
		}  
}
//in chieu cao cua cay
int max(int a, int b)
 {
 	if(a>=b)  return a;
 	else  return b;
 }
int chieucao(Node *goc)
  {
  	if(goc==NULL)   return 0;
  	else
  	  return 1+max(chieucao(goc->left),chieucao(goc->right));
  }
// int ra cac nut co chieu cao la 2
int innut2(Node *goc)
{
	if(goc!=NULL)
	 {
	   if(chieucao(goc)==3)
	  
	  	printf("%3d",goc->gtri);
	  	innut2(goc->left);
	  	innut2(goc->right);
		}  
}
//tinh tong cac nut chieu cao cay con phai cao hon chieu cao cay con trai

int tongpht(Node *goc)
{
	if(goc==NULL)
	  return 0;
	else
	  if((chieucao(goc->right))>chieucao(goc->left))
	    return goc->gtri+tongpht(goc->left)+tongpht(goc->right);
	    else
	    return tongpht(goc->left)+tongpht(goc->right);
}

// 1, sao chep cay
// 2, tai moi nut hoan doi cay con phai va cay con trai cho nhau
// 3, viet ham ktra 1 cay nhi phan co phai la cay nhi phan tim kiem? (phai->0; ko phai->1)

void saochep(Node *goc,Node *&goc1)
{
	if(goc==NULL)  goc1=NULL;
	else
	{
		goc1=new Node;
		goc1->gtri=goc->gtri;
		saochep(goc->left,goc1->left);
		saochep(goc->right,goc1->right);
	}
 } 
 
void hoandoi(Node *goc1)
{
	Node *tam;
	if (goc1!=NULL)
	{
		tam=goc1->left;
		goc1->left=goc1->right;
		goc1->right=tam;
		hoandoi(goc1->left);
		hoandoi(goc1->right);	
	}
}

int ktra(Node *goc)
{
	if (goc==NULL)   return 0;
	else
	  if((goc->left==NULL)&&(goc->right==NULL))  return 0;
	  else 
	    if((goc->left!=NULL)&&(goc->gtri<goc->left->gtri))  return 1;
	    else
	      if((goc->right!=NULL)&&(goc->gtri>goc->right->gtri))   return 1;
	      else
	        if(ktra(goc->left)+ktra(goc->right)!=0)  return 1;
	        else  return 0;
}
int main()
{
	khoitao(goc);
	khoitao(goc1);
	taocay(goc);
	printf("\n duyet LNR: \n");
	duyetLNR(goc);
	printf("\n so luong nut: %d", demnut(goc));
	printf("\n tong cac nut: %d", tongnut(goc));
	printf("\n so nut la: %d", demla(goc));
	printf("\n tong cac nut la chan: %d \n", tonglachan(goc));
	inla(goc);
	printf("\n chieucao: %d \n", chieucao(goc));
	innut2(goc);
	printf(" \n tong cac nut phai cao hon trai : %d",tongpht(goc));
	saochep(goc,goc1);
	printf("\n cay goc: \n");  duyetLNR(goc);
	printf("\n cay goc 1: \n");  duyetLNR(goc1);
	hoandoi(goc1);
	printf("\n cay goc 1 hoan doi: \n"); duyetLNR(goc1);
	printf("\n ktra goc: %d",ktra(goc));
	printf("\n ktra goc 1: %d",ktra(goc1));
	return 0;
}
