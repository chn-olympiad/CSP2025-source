//SN-J00522 李宸昊  西安市曲江第一学校
#include <bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a=b;a<=c;a++)
#define int long long
#define inf 0x3f3f3f3f
const int maxn=5e5+5;
int n,m,a[maxn],s[maxn],ans=-inf;
int dfs(int pos){
	int ret=0,rp=-1;
	rep(i,pos,n){
		if(s[i]^s[pos-1]==m){
			rp=i;
			break;
		}
	}
	if(rp==-1) return 0;
	rep(i,rp+1,n) ret=max(ret,dfs(i));
	return ret+1;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	rep(i,1,n){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	cout<<dfs(1);
	return 0;
}
