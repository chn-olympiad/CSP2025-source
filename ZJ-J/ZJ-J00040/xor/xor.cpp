#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAX=2e6+5,N=5e5+5;
int f[N],t[MAX],a[N],qz[N];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		qz[i]=qz[i-1]^a[i];
	}
	t[0]=0;
	for(int i=1;i<=(1<<20);i++){
		t[i]=-1;
	}
	for(int i=1;i<=n;i++){
		int l=qz[i]^k;
		f[i]=f[i-1];
		if(t[l]!=-1){
			f[i]=max(f[i],f[t[l]]+1);
		}
		t[qz[i]]=i;
	}
	cout<<f[n];
	return 0;
}
/*
4 2
2 1 0 3
*/
