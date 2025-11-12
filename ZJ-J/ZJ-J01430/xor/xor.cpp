#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,k;
int a[N];
map<int,int>mp;
int wh[N],now;
int f[N];
signed main(){
//	system("fc xor.out xor.ans");
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	mp[0]=0;
	memset(wh,-1,sizeof wh);
	for(int i=1;i<=n;i++){
		now^=a[i];
		if(mp[now^k]){
			wh[i]=mp[now^k];
		}
		else if(now==k){
			wh[i]=0;
		}
		mp[now]=i;
	}
	for(int i=1;i<=n;i++){
		f[i]=f[i-1];
		if(~wh[i]){
			f[i]=max(f[i],f[wh[i]]+1);
		}
	}
	cout<<f[n];
	return 0;
}
