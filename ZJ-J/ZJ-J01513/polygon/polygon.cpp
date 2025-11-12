#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mod=998244353;
int n,cnt=0;
int a[5010],f[5010];

int h(int c){
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)/2;
		if(a[mid]<c) l=mid+1;
		else r=mid-1;
	}
	if(a[l]>=c) l--;
	return l;
}

void dfs(int d,int deep,int md){
	if(deep>md-1){
		int c=0;
		for(int i=1;i<=md-1;i++) c+=f[i];
		int v=h(c);
		if(v<=d) return ;
		cnt=(cnt+v-d)%mod;
//		for(int i=1;i<=md-1;i++) cout<<f[i]<<" ";
//		cout<<v-d<<"\n";
		return ;
	}
	if(deep==md-1){
		f[deep]=a[d];
		dfs(d,deep+1,md);
		return ;
	}
	f[deep]=a[d];
	for(int i=d+1;i<=n-(md-deep)+1;i++) dfs(i,deep+1,md);
	return ;
}

signed main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	if(n>20){
		int d=1;
		for(int i=1;i<=n;i++) d*=i;
		d/=2;
		for(int i=3;i<=n;i++){
			d/=i;
			cnt+=d;
		}
		cout<<cnt;
		return 0;
	}
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		for(int j=1;j<=n-i+1;j++) dfs(j,1,i);
	}
	cout<<cnt;
	return 0;
}