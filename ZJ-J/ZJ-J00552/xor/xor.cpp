#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,a[N],f[N];
vector<int> mp[1050000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)f[i]=f[i-1]^a[i];
	int lst=0,ans=0;
	mp[0].emplace_back(0);
	for(int i=1;i<=n;i++){
		int op=f[i]^k;
		for(int j=0;j<mp[op].size();j++)if(mp[op][j]+1>lst){lst=i;ans++;break;}
		mp[f[i]].emplace_back(i);
	}
	cout<<ans;
	return 0;
}