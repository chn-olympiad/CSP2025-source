#include <bits/stdc++.h>
using namespace std;

int T;
int n; 
int a[10005][4];
int pd=0;

void read()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
			cin>>a[i][j]; 
		if(a[i][2]!=0)
			pd=1;
		if(a[i][3]!=0)
			pd=1;
	}
}

void do1()//n=2
{
	int anss=-1;
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
		{
			if(i==j)
				continue;
			anss=max(anss,a[1][i]+a[2][j]);
		}
	cout<<anss<<endl;
}

void do2()//n=4
{
	int anss=-1;
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
			for(int k=1;k<=3;k++)
				for(int l=1;l<=3;l++)
				{
					int rs[4]={0,0,0,0};
					rs[i]++,rs[j]++,rs[k]++,rs[l]++;
					if(rs[1]>2||rs[2]>2||rs[3]>2)
						continue;
					anss=max(anss,a[1][i]+a[2][j]+a[3][k]+a[4][l]);
				}
	cout<<anss<<endl;
}

void do3()//n=10
{
	int anss=1;
	for(int i1=1;i1<=3;i1++)
	for(int i2=1;i2<=3;i2++)
	for(int i3=1;i3<=3;i3++)
	for(int i4=1;i4<=3;i4++)
	for(int i5=1;i5<=3;i5++)
	for(int i6=1;i6<=3;i6++)
	for(int i7=1;i7<=3;i7++)
	for(int i8=1;i8<=3;i8++)
	for(int i9=1;i9<=3;i9++)
	for(int i10=1;i10<=3;i10++)
	{
		int rs[11]={0,0,0,0,0,0,0,0,0,0,0};
		rs[i1]++;rs[i2]++;rs[i3]++;rs[i4]++;rs[i5]++;
		rs[i6]++;rs[i7]++;rs[i8]++;rs[i9]++;rs[i10]++;
		if(rs[i1]>5||rs[i2]>5||rs[i3]>5||rs[i4]>5||rs[i5]>5||rs[i6]>5||rs[i7]>5||rs[i8]>5||rs[i9]>5||rs[i10]>5)
			continue;
		anss=max(anss,a[1][i1]+a[2][i2]+a[3][i3]+a[4][i4]+a[5][i5]+a[6][i6]+a[7][i7]+a[8][i8]+a[9][i9]+a[10][i10]);
	}
	cout<<anss<<endl;
} 

void do4()
{
	int anss=0;
	int b[10005];
	for(int i=1;i<=n;i++)
		b[i]=a[i][1];
	for(int i=1;i<=n;i++)
		for(int j=n;j>=i;j++)
			if(b[j]>b[j-1])
			{
				int s=b[j-1];
				b[j-1]=b[j];
				b[j]=s;
			}
	for(int i=1;i<=n/2;i++)
		anss+=b[i];
	cout<<anss<<endl;
 } 

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		read();
		if(n==2)
		{
			do1();
			continue;
		}
		if(n==4)
		{
			do2();
			continue;
		}
		if(n==10)
		{
			do3();
			continue;
		}
		if(pd==0)
		{
			do4();
			continue;
		}
	}
	return 0;
 } 
