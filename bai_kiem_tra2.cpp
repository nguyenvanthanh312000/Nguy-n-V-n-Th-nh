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
void duyetRLN(Node *goc) 
{
	if(goc != NULL) 
{
	duyetRLN(goc->right);
	duyetRLN(goc->left);
	printf("%3d",goc->gtri);
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
	  return 0;
	  else
	  return demla(goc->left)+demla(goc->right);
}
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

int main()
{
	khoitao(goc);
	khoitao(goc1);
	taocay(goc);
	printf("\n duyet RLN: \n");
	duyetRLN(goc);
	printf("\n so luong nut: %d", demnut(goc));
	printf("\n tong cac nut: %d", tongnut(goc));
	printf("\n so nut la: %d", demla(goc));
return 0;
}
