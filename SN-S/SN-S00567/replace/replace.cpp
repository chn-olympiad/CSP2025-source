#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e6+5,p=139,m=1e9+9;
int n,q,k;
char c[N][2];
ll a[N][2],pw[N];
map<pair<ll,ll>,int> mp;
ll gt(int l,int r,int o){return (a[r][o]-a[l-1][o]*pw[r-l+1]%m+m)%m;}
void hs(int o){
	k=0;
	char ch=getchar();
	while(ch<'a'||ch>'z') ch=getchar();
	while(ch>='a'&&ch<='z'){
		c[++k][o]=ch;
		a[k][o]=(a[k-1][o]*p+ch)%m;
		ch=getchar();
	}
}
void sol(){
	scanf("%d%d",&n,&q);
	while(n--){
		hs(0);
		hs(1);
		mp[{a[k][0],a[k][1]}]++;
	}
	while(q--){
		hs(0);
		int g=k;
		hs(1);
		if(g!=k){printf("0\n");continue;}
		int i=1,j=k;
		ll ans=0;
		while(i<=k&&c[i][0]==c[i][1]) i++;
		if(i>k){
			for(int l=1;l<=k;l++) for(int r=l;r<=k;r++) ans+=mp[{gt(l,r,0),gt(l,r,1)}];
		}else{
			while(j>=1&&c[j][0]==c[j][1]) j--;
			for(int l=1;l<=i;l++) for(int r=j;r<=k;r++) ans+=mp[{gt(l,r,0),gt(l,r,1)}];
		}
		printf("%lld\n",ans);
	}
}
void ii(){
	pw[0]=1;
	for(int i=1;i<N;i++) pw[i]=pw[i-1]*p%m;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ii();
//	int TT;for(scanf("%d",&TT);TT--;)
	sol();
	return 0;
}
