#include <stdio.h>
#include <string.h>

struct nut
{
	char gtri[80];
	nut *sau,*truoc;
};

typedef nut Node;
Node *dau;
char t[80];

void Khoitao(Node *&dau)
{
	dau=NULL;
}

void nhapvb(Node *&dau)
{
	char tam[80];
	Node *p,*q;
	do{
		printf("\n Nhap vao 1 xau : Nhan Enter de dung lai : ");
		gets(tam);
		if(strcmp(tam,"\0")!=0)
		{
			p=new Node;
			strcpy(p->gtri,tam);
			p->sau=NULL;
			p->truoc=NULL;
			if(dau==NULL)
			{
				dau=p;
			}
			else
			{
				q->sau=p;
				p->truoc=q;
			}
			q=p;
		}
	}
	while(strcmp(tam,"\0"));
}
void Duyet(Node *&dau)
{
	Node *p;
	p=dau;
	while(p!=NULL)
	{
		printf("\n %s",p->gtri);
		p=p->sau;
	}
}

int main()
{
	Khoitao(dau);
	nhapvb(dau);
	Duyet(dau);
	return 0;
}
