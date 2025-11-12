#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int N=5000;
int n,ans,a[N],kh;
void dfs(int x,int t,int la){
	if(la==n) return;
	if(t==x){
		for(int i=la+1;i<=n;i++){
			if(a[i]*2<kh+a[i]){
				ans++;
				ans%=mod;
			}else{
				return;
			}
		}
	}else{
		for(int i=la+1;i<=n-(x-t);i++){
			kh+=a[i];
			dfs(x,t+1,i);
			kh-=a[i];
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
		dfs(i,1,0);
	}
	printf("%d",ans);
	return 0;
}
