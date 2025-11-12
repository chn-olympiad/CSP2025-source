//雷博尧  SN-S00759  西安辅轮中学 
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int T;
int n;
int ans;
int a[5];
vector<int> d;
bool cmp(int x,int y)
{
	return x > y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		ans = 0;
		d.clear();
		cin>>n;
		for(int i = 1;i<=n;i++)
		{
			cin>>a[1]>>a[2]>>a[3];
			ans += a[1];
			d.push_back(min(a[1]-a[2],a[1]-a[3]));
		}
		sort(d.begin(),d.end());
		for(int i = 0;i<n/2;i++)
		{
			ans -= d[i];
		}
		cout<<ans<<'\n';
	}
 } 
