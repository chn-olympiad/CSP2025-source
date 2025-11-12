#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int const N=5010;
ll const p=998244353;
int n,a[N];
ll res;
bool sp=1;

ll res1,res2;

ll dfs(int x,int c,int s){
	ll cnt=0;
	for (int i=x+1;i<=n;i++){
		cnt+=dfs(i,c+1,s+a[i]);
		cnt%=p;
	}
	if (c>=3 && a[x]*2<s){
		cnt++;
	}
	return cnt%p;
}

ll Pow(ll x,int a){
	if (a==1) return x;
	if (!a) return 1;
	ll t=Pow(x,a>>1);
	if (a%2) return (t*t*x)%p;
	return (t*t)%p;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
		
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if (sp && a[i]!=1) sp=0;
	}
	sort(a+1,a+n+1);
	if (sp){
		res=Pow(2,n)-(n*(n-1)/2)-n-1;
		if (res<0) res+=p;
		printf("%lld",res);
		return 0;
	}
	res=dfs(0,0,0);
	printf("%lld",res);
	
	return 0;
} 
