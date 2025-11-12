#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 7;
int t,n,ans,cnt;
struct hzh{
	int a,b,c,d;
	bool k;
} l[MAXN];
bool cma(hzh x,hzh y){
	return x.a>y.a;
}
bool cmb(hzh x,hzh y){
	return x.b>y.b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		ans=0;
		int bj=n/2;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&l[i].a,&l[i].b,&l[i].c);
			l[i].d=max(max(l[i].a,l[i].b),l[i].c);
			l[i].k=false;
		}
		sort(l+1,l+n+1,cma);
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(cnt>=bj) break;
			if(l[i].d==l[i].a){
				ans+=l[i].d;
				cnt++;
				l[i].k=true;
			}
		}
		sort(l+1,l+n+1,cmb);
		cnt=0;
		for(int i=1;i<=n;i++){
			if(cnt>bj) break;
			if(l[i].k==false){
				if(l[i].d==l[i].a||l[i].d==l[i].b){
				ans+=l[i].b;
				cnt++;
				l[i].k=true;
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(l[i].k==false) ans+=l[i].c;
		}
		cout<<ans<<endl;
	}
	return 0; 
}