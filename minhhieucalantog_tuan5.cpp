#include<iostream.h>
#include<math.h>
#include <cstdlib>
#include <ctime>
#define maxn 100
#define maxm 100
 

void mangngaunhien(int a[],int &n);
void xuatmang(int a[],int n);
void caua(int a[],int n);
int nt(int n);
int ntsau(int n);
int nttruoc(int n);
void caub(int a[],int n);
void cau2(int a[],int n);
int sodoixung(int n);
void cauc(int a[],int n);
void mangngaunhien2(int a[maxn][maxm],int &k,int &m);
void xuatmang2(int a[maxn][maxm],int n,int m);
int khoangcachtren(int n);
int khoangcachduoi(int n);
void cau3a(int a[maxn][maxm],int b[maxn][maxm],int m,int n);
void cau3b(int a[maxn][maxm],int b[maxn][maxm],int m,int n);
void cau3c(int a[maxn][maxm],int b[maxn][maxm],int m,int n);
int slnt(int n,int m,int a[][maxm]);


int main()
{   
	int a[maxn],n,m,b[maxn][maxm],c[maxn][maxm],d[maxn][maxm],e[maxn][maxm];
	mangngaunhien(a,n);
	xuatmang(a,n);
	caua(a,n);
	caub(a,n);
    cau2(a,n);
    cauc(a,n); cout<<endl;
    mangngaunhien2(b,n,m);
    xuatmang2(b,n,m);
    cout<<endl;
    cau3a(b,c,n,m);
    xuatmang2(c,n,m);
    cau3b(b,d,n,m);
    xuatmang2(d,n,m);
    cau3c(b,e,n,m);
    xuatmang2(e,n,m);
    
    
    
cout<<endl;
return 0;	
}

void mangngaunhien(int a[],int &n)
{   cout<<"nhap n ";cin>>n;
    srand(time(0));
	for(int i=0;i<n;i++)
	{
		a[i] = rand()%200-100;
	}
}

void xuatmang(int a[],int n)
{
    for(int i=0;i<n;i++)
     	cout<<a[i]<<"  ";
     	cout<<endl;
     
}

void caua(int a[],int n)
{   int max2=0,max=0;
	for(int i=0;i<n;i++)
      {
      	if(a[i]>max) max=a[i];
      }
    for(int i=0;i<n;i++)
      {
	    if(a[i]>max2&&a[i]!=max) max2=a[i];
      }
	cout<<"cau 1_a_1: "<<max<<endl<<"cau 1_a_2: "<<max2<<endl;
	
}
int nt(int n)
{   
	if(n<2) return 0;
	float k=sqrt(n);
	for(int i=2;i<=k;i++)
      if(n%i==0) return 0;
      return 1;	
}


int ntsau(int n)
{
	do
	{
		n++;
	}
	while(nt(n)==0);
	return n;	
}

int nttruoc(int n)
{
	do
	{
		n--;
	}
	while(nt(n)==0);
	return n;	
}


void caub(int a[],int n)
{   cout<<"cau 1_b: ";
	for(int i=0;i<n;i++)
	{   
		if(nt(a[i])==1)
		{ 
		  if(( ntsau(a[i])+nttruoc(a[i]) )/2.0==a[i]) cout<<a[i]<<" ";
		}
	}
     cout<<endl;	
}

int sodoixung(int n)
{
	int doi=0;
	while(n>0)
	{
		doi=doi*10+n%10;
		n=n/10;
	}
	return doi;
}

void cau2(int a[],int n)
{
	cout<<"cau2_a: ";
	for(int i=0;i<n;i++)
	{
		if(a[i]==sodoixung(a[i]) )
	     {
		   cout<<a[i]<<"  ";	
	     }
	}
	cout<<endl<<"cau2_b: ";
	for(int i=0;i<n;i++)
	{
	   if(a[i]==sodoixung(a[i]) )
	     {
		   if(nt(a[i])==1)
		  	cout<<a[i]<<"  ";	
	     }
	}
	cout<<endl;	
		
}
void  cauc(int a[],int n)
{
	int dem=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			for(int k=j+1;k<n;k++)
			{
				if(a[i]+a[j]+a[k]==0)
				{
					dem++;					
				}
			}
		}
	}
	cout<<"cau2_c: "<<dem;
	
}

void mangngaunhien2(int a[maxn][maxm],int &k,int &m)
{
	cout<<endl;
	cout<<"nhap so dong ";cin>>k;
    cout<<"nhap so cot ";cin>>m;
    srand(time(0));
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<m;j++)
		{
			a[i][j] = rand()%10;
		}
	}
}

void xuatmang2(int a[maxn][maxm],int n,int m)
{   
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<a[i][j]<<"  ";
		}
		cout<<endl;
	}
	cout<<endl;
}
int khoangcachtren(int n)
{
	int kc=abs(ntsau(n)-n);
	return kc;	
}
int khoangcachduoi(int n)
{
	int kc=abs(nttruoc(n)-n);
	return kc;	
}
void cau3a(int a[maxn][maxm],int b[maxn][maxm],int m,int n)
{
	    cout<<"cau 3_a: " <<endl;
		for(int i=0;i<m;i++)
    	{
	    	for(int j=0;j<n;j++)
		     {
		     	if(a[i][j]==0||a[i][j]==1) b[i][j]=2;
		     	else
		     	{
		     	  if(nt(a[i][j])==1) b[i][j]=a[i][j];
	     	      else 
		     	   {
	     			 khoangcachtren(a[i][j])-khoangcachduoi(a[i][j])>0?b[i][j]=ntsau(a[i][j]):b[i][j]=nttruoc(a[i][j]);
	     		   }
		     	}
		     }
    	}
}

void cau3b(int a[maxn][maxm],int b[maxn][maxm],int m,int n)
{
	cout<<"cau 3_b: "<<endl;
	int max;
	for(int i=0;i<m;i++)
	{
		max=0;
		for(int j=0;j<n;j++)
		{
			if(a[i][j]>max) max=a[i][j];
		}
		for(int k=0;k<n;k++)
		{
			b[i][k]=max*a[i][k];
		}
	}
	cout<<endl;
}


int slnt(int h,int p,int a[maxn][maxm],int n,int m)
{
	int k=0,s=0,d=0;
	for(int i=0;i<n;i++)
	{
		if(nt(a[h][i])==1)  d++;
	}
	for(int j=0;j<m;j++)
	{
		if(nt(a[j][p])==1)  k++;
	}
	s=d+k;
	if(nt(a[h][p])==1) s--;
	return s;
}

void cau3c(int a[maxn][maxm],int b[maxn][maxm],int m,int n)
{
	cout<<"cau 3_c: "<<endl;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(nt(a[i][j]==1))  b[i][j]=a[i][j]*slnt(i,j,a,m,n)-1;
			else  b[i][j]=a[i][j]*slnt(i,j,a,m,n);
		}
	}
}