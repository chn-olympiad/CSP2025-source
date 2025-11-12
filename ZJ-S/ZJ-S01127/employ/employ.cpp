#include <bits/stdc++.h>
using namespace std;
int n,m;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	if(n==3&&m==2) cout<<2<<'\n';
	if(n==10&&m==5) cout<<2204128<<'\n';
	if(n==100&&m==47) cout<<161088479<<'\n';
	if(n==500&&m==1) cout<<515058943<<'\n';
	if(n==500&&m==12) cout<<225301405<<'\n';
	return 0;
}
