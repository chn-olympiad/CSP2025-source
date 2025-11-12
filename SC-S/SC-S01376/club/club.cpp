#include<bits/stdc++.h>
using namespace std;
#define refi freopen("club.in","r",stdin)
#define outfi freopen("club.out","w",stdout)
int t;
int n;
int d[3]={0,0,0};
struct mbr
{
	int a;
	int b;
	int c;
}a[100050];
int b[100050][3];
bool cmp(mbr x,mbr y)
{
	if(x.a>y.a)
		return true;
	else if(x.a<y.a)
		return false;
	else if(x.b>y.b)
		return true;
	else if(x.b<y.b)
		return false;
	else if(x.c>y.c)
		return true;
	else
		return false;
}
int gtmxi(int it)
{
	int kks=max(b[it][0],max(b[it][1],b[it][2]));
	if(kks==b[it][0])
		return 0;
	if(kks==b[it][1])
		return 1;
	if(kks==b[it][2])
		return 2;
}
int gtminx(int it)
{
	int kks=min(b[it][0],min(b[it][1],b[it][2]));
	if(kks==b[it][0])
		return 0;
	if(kks==b[it][1])
		return 1;
	if(kks==b[it][2])
		return 2;
}
int gtseci(int it)
{
	int kks=gtmxi(it);
	if(kks==0)
		return b[it][1]>=b[it][2]?1:2;
	if(kks==1)
		return b[it][0]>=b[it][2]?0:2;
	if(kks==2)
		return b[it][0]>=b[it][1]?0:1;
} 
long long work(int i)
{
	if(i>=n)
		return 0;
	long long ans=0;
	if(b[i][gtmxi(i)]==b[i][gtseci(i)])
	{
		if(b[i][gtmxi(i)]==b[i][gtminx(i)])
		{
			if(d[gtmxi(i)]<(n/2)){d[gtmxi(i)]++;}
			ans=work(i+1);
			if(d[gtseci(i)]<(n/2)){d[gtseci(i)]++;}
			ans=max(ans,work(i+1));
			if(d[gtminx(i)]<(n/2)){d[gtminx(i)]++;}
			ans=max(ans,work(i+1));
			ans+=b[i][gtmxi(i)];
		}
		else
		{
			if(d[gtmxi(i)]<(n/2)){d[gtmxi(i)]++;}
			ans=work(i+1);
			if(d[gtseci(i)]<(n/2)){d[gtseci(i)]++;}
			ans=max(ans,work(i+1));
			ans+=b[i][gtmxi(i)];
		}
	}
	else if(d[gtmxi(i)]<(n/2))
	{
		ans+=b[i][gtmxi(i)];
		d[gtmxi(i)]++;
		ans+=work(i+1);
	}
	else
	{
		int k=gtmxi(i),kk=gtseci(i),q=gtmxi(i-1),qq=gtseci(i-1);
		if(b[i-1][q]+b[i][kk]<b[i-1][qq]+b[i][k])
		{
			ans=ans-b[i-1][q]+b[i-1][qq]+b[i][k];
			d[qq]++;
			ans+=work(i+1); 
		}
		else
		{
			ans+=b[i][kk];
			d[kk]++;
			ans+=work(i+1);
		}
	}
	return ans;
}
int main()
{
	refi;
	outfi;
	
	cin>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(d,0,sizeof(d));
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>a[i].a>>a[i].b>>a[i].c;
		sort(a,a+n,cmp);
		for(int i=0;i<n;i++)
		{
			b[i][0]=a[i].a;
			b[i][1]=a[i].b;
			b[i][2]=a[i].c;
		}
		cout<<work(0)<<endl;
	}
	return 0;
} 