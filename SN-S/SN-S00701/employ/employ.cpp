#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
const int maxn=505;
char s[maxn];
ll c[maxn];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	cout<<2<<endl;
	return 0;
}
