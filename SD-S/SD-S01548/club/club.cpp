#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+10;
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}

	return x*f;
}
int T,n;
int a[N][5];
int b[N];
int c[5];
bool cmp(int x,int y)
{
	return x>y;
}


int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--)
	{
		n=read();
		c[1]=c[2]=c[3]=0;
		for(int i=1;i<=n;i++)
		{
			b[i]=-1e9;
			a[i][1]=read(),a[i][2]=read(),a[i][3]=read();	
			if(a[i][1]>a[i][2]&&a[i][1]>a[i][3])c[1]++;
			else if(a[i][2]>a[i][1]&&a[i][2]>a[i][3])c[2]++;
			else if(a[i][3]>a[i][1]&&a[i][3]>a[i][2])c[3]++;
		}
		int mx;
		if(c[1]>c[2]&&c[1]>c[3])mx=1;
		else if(c[2]>c[1]&&c[2]>c[3])mx=2;
		else mx=3;
		//cout<<c[1]<<' '<<c[2]<<' '<<c[3]<<'\n';
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			sum+=a[i][mx];
			for(int k=1;k<=3;k++)
			{
				if(k==mx)continue;
				b[i]=max(a[i][k]-a[i][mx],b[i]);
			}
		}
		//cout<<mx<<' '<<sum<<'\n';
		sort(b+1,b+1+n,cmp);
		//int cnt=0;
		for(int i=1;i<=max(n-c[mx],n/2);i++)
		{
			//1
			//if(b[i]<0&&c[mx]-i<=n/2)break;
			//cout<<b[i]<<'\n';
			sum+=b[i];
		}
	//	cout<<cnt<<'\n';
		cout<<sum<<'\n';
	}
	return 0;
}

