#include <stdio.h>
#include<string.h>

struct nut{
	char gtri[80];
	nut *sau,*truoc;
};

typedef nut Node;
Node *dau;
char t[80];

void khoitao(Node *&dau)
{
	dau=NULL;
}

void nhapvb(Node *&dau)
{
	char tam[80];
	Node *p,*q;
	do{
		printf("\n Nhap 1 xau, Enter:dung \t");
		gets(tam);
		if(strcmp(tam,"\0")!=0)
		{
			p=new Node;
			strcpy(p->gtri,tam);
			p->sau=NULL;
			p->truoc=NULL;
			if(dau==NULL)
				dau=p;
			else
			{
				q->sau=p;
				p->truoc=q;
				
			}
			q=p;
		}
	}
	while(strcmp(tam,"\0")!=0);
}
void duyet(Node *dau)
{
	Node *p;
	p=dau;
	while(p!=NULL)
	{
		printf("\n %s",p->gtri);
		p=p->sau;
	}
}
void themdau(Node *&dau, char x[80])
{
	Node *p;
	p=new Node;
	strcpy(p->gtri,x);
	p->sau=dau;
	dau->truoc=p;
	dau=p;
}
void themcuoi(Node *&dau,char x[80])
{
	Node *p,*q;
	q=new Node;
	strcpy(q->gtri,x);
	q->sau=NULL;
	q->truoc=NULL;
	//tim nut cuoi
	if(dau==NULL)
		dau=q;
		else
		{
			p=dau;
			while((p!=NULL)&&(p->sau!=NULL))
			p=p->sau;
			//p dia chi nut cuoi
			p->sau=q;
			//q->truoc=p;
		}
}
void xoadong(Node *&dau,int i)
{
	Node *p,*t,*s;
	int d;
	p=dau;
	d=1;
	while((p!=NULL)&&(d<i))
	{
		p=p->sau;
		d=d+1;
	}
	if(p!=NULL)
	{
		if(p==dau)
		{
			dau=dau->sau;
			dau->truoc=NULL;
			delete p;
		}
		else
		{
			if((p->truoc!=NULL)&&(p->sau!=NULL))
			{
				t=p->truoc;
				s=p->sau;
				t->sau=s;
				s->truoc=t;
				delete p;
			}
			else
			{
				t=p->truoc;
				t->sau=NULL;
				delete p;
			}
		}
		
	}
}
int main()
{
	
	khoitao(dau);
	nhapvb(dau);
	duyet(dau);
	/*strcpy(t,"Dong dau");
	themdau(dau,t);
	duyet(dau);
	strcpy(t,"Dong cuoi");
	themcuoi(dau,t);
	duyet(dau);*/
	int i;
	printf("Nhap vao dong can xoa:");
	scanf("%d",&i);
	xoadong(dau,i);
	printf("\n Da xoa dong i \n");
	duyet(dau);
	return 0;
}
