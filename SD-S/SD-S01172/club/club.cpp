#include<bits/stdc++.h>
using namespace std;
namespace fr{
	int read()
	{
		int x=0,flag=1;
		char c=getchar();
		for(;!isdigit(c);c=getchar())if(c=='-')flag=-1;
		for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-'0';
		return x*flag;
	}
}
using namespace fr;
const int N = 6e5+5;
struct data
{
	int w,id;
};
bool operator <(data a,data b)
{
	return a.w>b.w;
}
struct t1{
	int w1,w2;
};
bool cmp(t1 a,t1 b)
{
	return max(a.w1,a.w2)>max(b.w1,b.w2);
}
int a[3][N];
void solve()
{
	int ans=0;
	int n=read();
	vector<data> s[3];
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<3;j++)a[j][i]=read();
		if(a[0][i]>a[1][i])
		{
			if(a[0][i]>a[2][i])s[0].push_back({a[0][i],i}),ans+=a[0][i];
			else s[2].push_back({a[2][i],i}),ans+=a[2][i];
		}
		else 
		{
			if(a[1][i]>a[2][i])s[1].push_back({a[1][i],i}),ans+=a[1][i];
			else s[2].push_back({a[2][i],i}),ans+=a[2][i]; 
		}
	}
	int rt=-1;
	for(int i=0;i<3;i++)if(s[i].size()>n/2)rt=i;
	if(rt==-1){
		cout<<ans<<endl;
		return;
	}
	vector<t1> now;
	for(data p:s[rt])
	{
		t1 x={1,1};
		for(int i=0;i<3;i++)
		{
			if(i==rt)continue;
			if(x.w1==1)x.w1=a[i][p.id]-p.w;
			else x.w2=a[i][p.id]-p.w;
		}
		now.push_back(x);
	}
	sort(now.begin(),now.end(),cmp);
	int cnt=now.size();
	for(t1 p:now)
	{
		ans+=max(p.w1,p.w2);
		--cnt;
		if(cnt<=n/2){
			cout<<ans<<endl;return;
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	int st=clock();
	int t=read();
	while(t--)solve();
//	int ed=clock();
//	cerr<<"\ntime:"<<ed-st<<"ms"<<endl;
	return 0;
}

