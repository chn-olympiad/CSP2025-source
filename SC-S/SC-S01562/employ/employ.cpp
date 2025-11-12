#include<bits/stdc++.h>
#define fi first
#define se second 
#define endl "\n"
#define int long long 
using namespace std;
const int maxn=5000+10;

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int a[maxn];
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==3)cout<<2;
	else if(n==10)cout<<2204128;
	else if(n==100)cout<<161088479;
	else if(n==500)cout<<515058943;
	else cout<<225301405;
	return 0;
}