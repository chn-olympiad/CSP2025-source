#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=998244353;
int n,a[5010],ans,p;
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
void dfs(int x,int l,int mx,int k,int f){
	if(k>=3&&l>mx*2&&!f) ans++,ans%=MOD;
	if(x==n+1) return;
	dfs(x+1,l+a[x],max(mx,a[x]),k+1,0);
	dfs(x+1,l,mx,k,1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) a[i]=read(),p=max(p,a[i]);
	if(p==1){
		ll d1=n*(n-1),d2=2,ans2=0;
		for(ll i=3;i<=n;i++){
			d2*=i;d2%=MOD;d1*=(n-i+1);d1%=MOD;
			ans2+=d1/d2;ans2%=MOD;
		}
		printf("%lld",ans2);
	}
	else dfs(1,0,0,0,0),printf("%d",ans);
}
