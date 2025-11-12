#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int g[5009];
bool st[5009];
int n;
long long ans=0;
int x=-0x3f3f3f3f;
long long cnt=0;
void dfs(int ceng){
	if(ceng>n){
		for(int i=1;i<=n;i++){
			if(st[i]){
				cnt=(cnt+g[i])%N;
				x=max(x,g[i]);
			}
		}
		if(cnt>x*2){
			ans=(ans+1)%N;
		}
		cnt=0;
		return;
	}
	for(int i=0;i<2;i++){
		st[ceng]=i;
		dfs(ceng+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>g[i];
	dfs(1);
	cout<<ans;
	return 0;
}
