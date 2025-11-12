#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
void read(int &x){
	x=0;ll sgn=1;char ch=getchar();
	while(!(ch>='0'&&ch<='9')){
		if(ch=='-')sgn=-1;
		ch=getchar();
	}
	while((ch>='0'&&ch<='9')){
		x=x*10+(ch^48);
		ch=getchar();
	}
	x=x*sgn;
}
void read(ll &x){
	x=0;ll sgn=1;char ch=getchar();
	while(!(ch>='0'&&ch<='9')){
		if(ch=='-')sgn=-1;
		ch=getchar();
	}
	while((ch>='0'&&ch<='9')){
		x=x*10+(ch^48);
		ch=getchar();
	}
	x=x*sgn;
}
const int N=2e5+5;
ll n,tt[N],mn[N],c[N],ans[5],cc[N],a[N][5],p[N],aa;
void solve(){
	aa=0;
	read(n);
	ans[1]=ans[2]=ans[3]=0;
	for(int i=1;i<=n;i++){
		read(a[i][1]);read(a[i][2]);read(a[i][3]);
		tt[i]=max(a[i][1],max(a[i][2],a[i][3]));
		aa+=tt[i];
		mn[i]=min(a[i][1],min(a[i][2],a[i][3]));
		cc[i]=a[i][1]+a[i][2]+a[i][3]-tt[i]-mn[i];
		if(tt[i]==a[i][1])c[i]=1,ans[1]++;
		else if(tt[i]==a[i][2])c[i]=2,ans[2]++;
		else if(tt[i]==a[i][3])c[i]=3,ans[3]++;
	}
	int cnt=0;
	for(int i=1;i<=3;i++){
		if(ans[i]>n/2){
			for(int j=1;j<=n;j++){
				if(c[j]==i){
					p[++cnt]=tt[j]-cc[j];
				}
			} 
			sort(p+1,p+cnt+1);
			for(int j=1;j<=cnt;j++){
				if(ans[i]-j+1<=n/2)break;
				aa-=p[j];
			}
			break;
		}
	}
	printf("%lld\n",aa);
}
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;read(T);
	while(T--)solve();
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/

