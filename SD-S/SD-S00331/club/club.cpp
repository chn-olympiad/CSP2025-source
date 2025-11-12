#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=1e5+10;
int t,n,cnt1,cnt2,cnt3,cnt,ans;
vector<pii>a,b,c;
bool cmp(pii x,pii y)
{
	return x.second<y.second;
}
void solve()
{
	cnt1=cnt2=cnt3=cnt=ans=0;
	a.clear();b.clear();c.clear();
	cin>>n;
	for(int i=1;i<=n;i++)
	{
	  int x,y,z,d;
	  cin>>x>>y>>z;
	  d=max(x,max(y,z));
	  ans+=d;
	  if(x==d)  a.push_back(make_pair(x,min(x-y,x-z))),cnt1++;
	  else  if(y==d)  b.push_back(make_pair(y,min(y-x,y-z))),cnt2++;
	  else  c.push_back(make_pair(z,min(z-x,z-y))),cnt3++;
	}
	cnt=max(cnt1,max(cnt2,cnt3));
	if(cnt<=n/2){
		cout<<ans<<"\n";
		return;
	}
	if(cnt1>n/2)
	{
	  sort(a.begin(),a.end(),cmp);
	  cnt1-=n/2;
	  for(int i=0;i<=cnt1-1;i++)  ans-=a[i].second;
	  cout<<ans<<"\n";	
	}
	
	if(cnt2>n/2)
	{
	  sort(b.begin(),b.end(),cmp);
	  cnt2-=n/2;
	  for(int i=0;i<=cnt2-1;i++)  ans-=b[i].second;
	  cout<<ans<<"\n";	
	}
	if(cnt3>n/2)
	{
	  sort(c.begin(),c.end(),cmp);
	  cnt3-=n/2;
	  for(int i=0;i<=cnt3-1;i++)  ans-=c[i].second;
	  cout<<ans<<"\n";	
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--)  solve();
	return 0;
}

