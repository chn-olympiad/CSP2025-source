#include<bits/stdc++.h>
using namespace std;
#define int long long
int c[505];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	int mul=1;
	int cnt1=n,cnt2=1;
	int cnt=0;
	for(int i=1;i<=m;i++)
	{
		if(c[i]==0)
		{
			cnt++;
			continue;
		}
		mul=mul*cnt1/cnt2%998244353;
		cnt1--;
		cnt2++;
	}
	cout<<mul;
	return 0;
} 
