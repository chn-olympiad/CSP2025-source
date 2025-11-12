#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
void Ios(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
const int maxn=1e5+10;
int a[maxn][3];
vector<int> cs1,cs2,cs3;
void solve()
{
	cs1.clear(),cs2.clear(),cs3.clear();
	int n;
	cin>>n;
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][0]>>a[i][1]>>a[i][2];
		int mx=max(max(a[i][0],a[i][1]),a[i][2]);
		int gqh=0;
		if(a[i][0]==mx) ans+=a[i][0],gqh=max(a[i][1],a[i][2]);
		else if(a[i][1]==mx) ans+=a[i][1],gqh=max(a[i][0],a[i][2]);
		else ans+=a[i][2],gqh=max(a[i][0],a[i][1]);
		gqh=mx-gqh;
		if(a[i][0]==mx) cs1.pb(gqh);
		else if(a[i][1]==mx) cs2.pb(gqh);
		else cs3.pb(gqh);
	}
	sort(cs1.begin(),cs1.end());
	sort(cs2.begin(),cs2.end());
	sort(cs3.begin(),cs3.end());
	if(cs1.size()>n/2)
	{
		int u=cs1.size()-n/2;
		for(int i=0;i<u;i++) ans-=cs1[i];
	}
	else if(cs2.size()>n/2)
	{
		int u=cs2.size()-n/2;
		for(int i=0;i<u;i++) ans-=cs2[i];
	}
	else if(cs3.size()>n/2)
	{
		int u=cs3.size()-n/2;
		for(int i=0;i<u;i++) ans-=cs3[i];
	}
	cout<<ans<<"\n";
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	Ios();
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}
//14:46 pretest passed(5)