#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int p=998244353;
int n,m,s[505],c[505];
ll l=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=1;i<=n;i++)cin>>c[i];
	for(ll i=1;i<=n;i++)(l*=i)%=p;
	cout<<l;
	return 0;
} 
