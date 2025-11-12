#include<bits/stdc++.h>
#define N 100005
#define ll long long
#define dd double
using namespace std;

struct node
{
	int x;
	int y;
};

inline void sort_(node a[],int n)
{
	for(int i=1;i<n;++i)
	{
		for(int j=i+1;j<=n;++j)
		{
			if(a[i].y>a[j].y)
			{
				swap(a[i].y,a[j].y);
				swap(a[i].x,a[j].x);
			}
		}
	}
}

int z,val;
int T;
int n;
int a[N][4];
node fir[N],sec[N],thir[N];

inline void pd(int a,int b,int c)
{
	if(a>=b)
	{
		if(a>=c) z=1,val=a;
		else z=3,val=c;
	}
	else
	{
		if(b>=c) z=2,val=b;
		else z=3,val=c;
	}
}

signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--)
	{
		memset(a,0,sizeof(a));
		cin >> n;
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=3;++j)
			{
				cin >> a[i][j];
			}
		}// ‰»Î 
		
		int siza=0,sizb=0,sizc=0;
		ll sum=0,sum_=0,sum__=0;
		for(int i=1;i<=n;++i)
		{
			pd(a[i][1],a[i][2],a[i][3]);
			if(z==1) 
			{
				siza++;
				fir[siza].x=i,fir[siza].y=val-max(a[i][2],a[i][3]);
				sum+=val;
			}
			else if(z==2)
			{
				sizb++;
				sec[sizb].x=i,sec[sizb].y=val-max(a[i][1],a[i][3]);
				sum_+=val;
			}
			else
			{
				sizc++;
				thir[sizc].x=i,thir[sizc].y=val-max(a[i][1],a[i][2]);
				sum__+=val;
			}
		}
		
		if(siza<=n/2 && sizb<=n/2 && sizc<=n/2) 
		{
			cout << sum+sum_+sum__ << "\n";
			continue;
		}
		
		int t_=0;
		int n_;
		int b[N/2][3];
		if(siza>n/2)
		{
			n_=siza;
			sort_(fir,n_);
			for(int i=1;i<=n_-n/2;++i)
			{
				sum-=fir[i].y;
				t_++;
				b[t_][1]=a[fir[i].x][2],b[t_][2]=a[fir[i].x][3];
			}
			siza=n/2-sizb;
			sizb=n/2-sizc;
			n_=n_-n/2;
		}
		else if(sizb>n/2)
		{
			n_=sizb;
			sort_(sec,n_);
			for(int i=1;i<=n_-n/2;++i)
			{
				sum_-=sec[i].y;
				t_++;
				b[t_][1]=a[sec[i].x][1],b[t_][2]=a[sec[i].x][3];	
			}
			siza=n/2-siza;
			sizb=n/2-sizc;
			n_=n_-n/2;
		}
		else
		{
			n_=sizc;
			sort_(thir,n_);
			for(int i=1;i<=n_-n/2;++i)
			{
				sum__-=thir[i].y;
				t_++;
				b[t_][1]=a[thir[i].x][1],b[t_][2]=a[thir[i].x][2];
			}
			siza=n/2-siza;
			sizb=n/2-sizb;
			n_=n_-n/2;
		}
		
		int t=0,tt=0;
		node c[N/2],d[N/2];
		for(int i=1;i<=n_;++i)
		{
			if(b[i][1]>=b[i][2])
			{
				t++;
				c[t].x=i,c[t].y=b[i][1]-b[i][2];
			}
			else
			{
				tt++;
				d[tt].x=i,d[tt].y=b[i][2]-b[i][1];
			}
		}
		if(t<=siza && tt<=sizb)
		{
			cout << sum+sum_+sum__ << "\n";
			continue;
		}
		if(t>siza)
		{
			sort_(c,t);
			for(int i=1;i<=siza-t;++i)
			{
				sum-=c[i].y;
			}
		}
		else
		{
			sort_(d,tt);
			for(int i=1;i<=sizb-tt;++i)
			{
				sum-=c[i].y;
			}
		}
		cout << sum+sum_+sum__ << "\n";
	}
	return 0;
}
