#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int,int>

const int N=3e5+10;
int n,m,k;
template <typename T> void tomax(T &a,const T &b){if(a<b) a=b;}
template <typename T> void tomin(T &a,const T &b){if(b<a) a=b;}

struct A{
	int x,y,z;
}a[N];

struct W{
	int id,w,op;
	bool operator < (const W &a2) const {return w<a2.w;}
}w[N];
bool ischo[N];
int work()
{
	int n1=0,n2=0,n3=0;
	int res=0;
	for(int i=1;i<=n;i++)
	{
		res+=a[i].x;
		int w2=a[i].x-a[i].y,w3=a[i].x-a[i].z;
		w[i*2-1]=(W){i,w2,2};
		w[i*2]=(W){i,w3,3};
		ischo[i]=0;
	}
	sort(w+1,w+1+n*2);
	n1=n;
	for(int i=1;i<=n*2;i++)
	{
		int ww=w[i].w,id=w[i].id,whe=w[i].op;
//		printf("in(%d %d),res=%d\n",ww,whe,res);
		if(ischo[id]) continue;
		if(ww>0&&n1<=n/2) return res;
		if(whe==2)
		{
			if(n2==n/2) continue;
			n2++,res-=ww;
			n1--;
		}
		if(whe==3)
		{
			if(n3==n/2) continue; 
			n3++,res-=ww;
			n1--;
		}
		ischo[id]=1;
	}
	return res;
}

namespace S1{
	const int N=210+10;
	int f[N][N][N];
	void SOLVE()//55pts
	{
		int res=0;
		for(int i=1;i<=n;i++)
		{
			for(int n1=0;n1<=i;n1++)
			{
				for(int n2=0;n2<=i-n1;n2++)
				{
					int n3=i-n1-n2;
					if(max(n1,max(n2,n3))>n/2) continue;
					f[n1][n2][n3]=0;
					if(n1) tomax(f[n1][n2][n3],f[n1-1][n2][n3]+a[i].x);
					if(n2) tomax(f[n1][n2][n3],f[n1][n2-1][n3]+a[i].y);
					if(n3) tomax(f[n1][n2][n3],f[n1][n2][n3-1]+a[i].z);
					tomax(res,f[n1][n2][n3]);
				}
			}
		}
		cout<<res<<'\n';
	}
}

void SOLVE()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].z);
	if(n<=200) return S1::SOLVE(),void();
	int res=0;
	tomax(res,work());
	for(int i=1;i<=n;i++) swap(a[i].x,a[i].y);
	tomax(res,work());
	for(int i=1;i<=n;i++) swap(a[i].x,a[i].z);
	tomax(res,work());
	cout<<res<<'\n';
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=1;
	scanf("%d",&T);
	while(T--) SOLVE();
	return 0;
}
