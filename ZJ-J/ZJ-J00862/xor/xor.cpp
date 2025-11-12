#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int l,r;
}qj[10000006];
int n,k,a[500005],d[500005][30],c[30],ans=0,cnt=0;
bool check(int l,int r){
	for(int i=0;i<=20;i++){
		if((d[r][i]-d[l-1][i])%2!=c[i])return false;
	}
	return true;
}
bool mark[1000006];
signed main(void){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	int x=k;
	for(int i=0;i<=20;i++){
		c[i]=(x&1);
		x>>=1;
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		int x=a[i];
		for(int j=0;j<=20;j++){
			d[i][j]=(x&1);
			d[i][j]+=d[i-1][j];
			x>>=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(check(i,j)){
				node k;
				k.l=i;k.r=j;
				qj[++cnt]=k;
				break;
			}
		}
	}
	int last=1;
	for(int i=2;i<=cnt;i++){
		if(qj[last].r>=qj[i].r){
			mark[last]=1;last=i;
			continue;
		}
		if(qj[last].r>=qj[i].l){
			mark[i]=1;
			continue;
		}
		last=i;
	}
	for(int i=1;i<=cnt;i++){
		ans+=(!mark[i]);
	}
	printf("%lld\n",ans);
    return 0;
}
