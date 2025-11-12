#include<bits/stdc++.h>
#define endl "\n"
#define f(n) for(int i=1;i<=n;i++)
#define int long long
#define IOS cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
using namespace std;
int T,n,suma,sumb,sumc,ans;
struct P{int maxa,smxa,mina,chax,chai,a[4];}p[100005];
bool cmp(P x,P y){
	if(x.chax>y.chax||(x.chax==y.chax&&x.chai>y.chai))return 1;
	return 0;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	IOS;cin>>T;
	while(T--){
		suma=0,sumb=0,sumc=0,ans=0;
		cin>>n;
		f(n){
			cin>>p[i].a[1]>>p[i].a[2]>>p[i].a[3];
			if(p[i].a[1]>=p[i].a[2]&&p[i].a[1]>=p[i].a[3]){
				if(p[i].a[2]>=p[i].a[3])p[i].smxa=2,p[i].mina=3;
				else p[i].smxa=3,p[i].mina=2;
				p[i].maxa=1;
			}else if(p[i].a[2]>=p[i].a[1]&&p[i].a[2]>=p[i].a[3]){
				if(p[i].a[1]>=p[i].a[3])p[i].smxa=1,p[i].mina=3;
				else p[i].smxa=3,p[i].mina=1;
				p[i].maxa=2;
			}else{
				if(p[i].a[1]>=p[i].a[2])p[i].smxa=1,p[i].mina=2;
				else p[i].smxa=2,p[i].mina=1;
				p[i].maxa=3;
			}
			p[i].chax=p[i].a[p[i].maxa]-p[i].a[p[i].smxa];
			p[i].chai=p[i].a[p[i].smxa]-p[i].a[p[i].mina];
		}
		sort(p+1,p+1+n,cmp);
		f(n){
			int aa=0,bb=0,cc=0;
			if(p[i].maxa==1){
				if(suma<n/2)aa=1;
				else{
					if(p[i].smxa==2){
						if(sumb<n/2)bb=1;
						else cc=1;
					}else{
						if(sumc<n/2)cc=1;
						else bb=1;
					}
				}
			}else if(p[i].maxa==2){
				if(sumb<n/2)bb=2;
				else{
					if(p[i].smxa==1){
						if(suma<n/2)aa=1;
						else cc=1;
					}else{
						if(sumc<n/2)cc=1;
						else aa=1;
					}
				}
			}else{
				if(sumc<n/2)cc=1;
				else{
					if(p[i].smxa==1){
						if(suma<n/2)aa=1;
						else bb=1;
					}else{
						if(sumb<n/2)bb=1;
						else aa=1;
					}
				}
			}
			if(aa)suma++,ans+=p[i].a[1];
			else if(bb)sumb++,ans+=p[i].a[2];
			else sumc++,ans+=p[i].a[3];
		}
		cout<<ans<<endl;
	}
	return 0;
}
