#include <bits/stdc++.h>
using namespace std;
int m,n,a[501000];
long long ss[501000],tot=1,ans;
bool cmp(const int &A,const int &B){
	return A>B;
}
void dfs(int s,int maxv,int f,int x){
	if(s>2*maxv&&f==1){
		ans+=ss[n-x]+1;
		ans%=998244353;
		return;
	}
	if(x>=n){
		return;
	}
	dfs(s+a[x+1],max(maxv,a[x+1]),1,x+1);
	dfs(s,maxv,0,x+1);
} 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1,cmp);
	ss[1]=1;
	for(int i=2;i<=n;i++){
		tot*=2;
		tot%=998244353;
		ss[i]=ss[i-1]+tot;
		ss[i]%=998244353;
	}
	dfs(0,0,0,1);
	dfs(a[1],a[1],1,1);
	printf("%lld",ans);
	return 0;
}
