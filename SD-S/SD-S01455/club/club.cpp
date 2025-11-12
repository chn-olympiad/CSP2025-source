#include<bits/stdc++.h>
#define int long long
#define endl '\n' 
using namespace std;
int n,m,cnt[5],ans;
struct node
{
	int id,x;
};
vector<node> a[114514];
bool cmp(node e,node f)
{
	return e.x>f.x;
 } 
bool cmp1(vector<node> e,vector<node> f)
{
	if(e[0].x==f[0].x)
	{
		if(e[1].x==f[1].x)
		{
			if(e[2].x==f[2].x) return e[2].id<f[2].id; 
			return e[2].x>f[2].x;
		}
		return e[1].x>f[1].x;
	}
	return e[0].x>f[0].x;
}
void solve()
{
	ans=0;
	cnt[0]=cnt[1]=cnt[2]=0;
	cin>>n;
	m=3;
	for(int i=0;i<n;i++)
	{
		//a.push_back(gunmu);
		//while(a[i].size()) a[i].pop_back();
		for(int j=0;j<m;j++) 
		{
			if(a[i].size()<m)a[i].push_back((node){0,0});
			cin>>a[i][j].x;
			a[i][j].id=j;
		}
		//cout<<1<<endl;
		sort(a[i].begin(),a[i].end(),cmp);
	}
	sort(a,a+n,cmp1);
	for(int i=0;i<n;i++)
	{
		int j=0;
		while(cnt[a[i][j].id]>=n/2) j++;
		cnt[a[i][j].id]++;
		ans+=a[i][j].x;
		cout<<a[i][j].x<<' '<<a[i][j].id<<endl;
	}
	for(int i=0;i<3;i++) cout<<cnt[i]<<" ";
	cout<<endl; 
	cout<<ans<<endl;
}//
signed main()
{ 	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);	
	int _;
	cin>>_;
	while(_--) solve();
	return 0;
 } 
