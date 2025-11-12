#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int N=1e5+10;
int n;
int a[N][5];
int mx[N];

void solve()
{
	int sum=0;
	vector<int> b[4];
	for(int i=1;i<=n;i++) mx[i]=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			cin>>a[i][j];
		}
		a[i][0]=-1;
		for(int j=1;j<=3;j++)
		{
			if(a[i][j]>a[i][mx[i]]) mx[i]=j;
		}
		sum+=a[i][mx[i]];
		b[mx[i]].push_back(i);
//		cerr<<mx[i]<<endl;
	}
	int t=0;
	for(int i=1;i<=3;i++)
	{
		if(b[i].size()>n/2) {t=i;break;}
	}
	if(!t){cout<<sum<<endl;return ;}
	int k=b[t].size()-n/2;
	vector<int> c;
	for(auto e:b[t])
	{
		c.push_back(-INF);
		for(int i=1;i<=3;i++)
		{
			if(mx[e]==i) continue;
			c.back()=max(c.back(),a[e][i]-a[e][mx[e]]);
		}
	}
	sort(c.begin(),c.end(),[&](int a,int b){return a>b;});
	for(int i=0;i<k;i++) sum+=c[i];
	cout<<sum<<endl; 
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
	return 0;
}
