#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10001],x,t,g,z;
void dfs(long long k,long long s){
	if(k>g-1 and s>a[g]){
		z++;
		z%=998244353;
		return ;
	}
	else if(k>g-1) return ;
	else if(s>a[g]){
		int p=1;
		for(int i=k;i<=g-1;i++){
			p*=2;
			p%=998244353;
		}
		z+=p;
		z%=998244353;
		return ;
	}
	dfs(k+1,s+a[k]);
	dfs(k+1,s);
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	if(n<=20){
		for(int i=3;i<=n;i++){
			g=i,z=0;
			dfs(1,0);
			t+=z;
			t%=998244353;
		}
		printf("%lld",t);
	}
	else{
		for(int i=3;i<=n;i++){
			int cc=1;
			for(int j=1;j<=i;j++){
				cc*=((n+1-j)/j)%998244353;
				cc%=998244353;
			}
			t+=cc;
			t%=998244353;
		}
		printf("%lld",t);
	}
	return 0;
}
//laozihuirenweizijishangshanruoshuima?
