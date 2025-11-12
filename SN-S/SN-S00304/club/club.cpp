#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int n,pd[4];
long long ans;
bool vis[N];
struct point{
	int r1,r2,id;
	int a,b,c;
}e[N<<2];
bool cmp(const point &a,const point &b ){
	if (a.r1!=b.r1)return a.r1>b.r1;
	return a.r2>b.r2;
}
void pre(){
	memset(e,0,sizeof e);
	ans=0;
	memset(vis,0,sizeof vis);
	memset(pd,0,sizeof pd);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int T;
	cin>>T;
	while(T--){
		pre();
		cin>>n;
		int tot=0;
		for(int i=1;i<=n;i++){
			cin>>e[i].a>>e[i].b>>e[i].c;
			int x=e[i].a,y=e[i].b,z=e[i].c;
			int nn=min(x,min(y,z));
			int mm=max(x,max(y,z));
			int pp,qq;
			if(nn==x){
				if(mm==y){
					pp=mm-z;qq=z-nn;
				}else{
					pp=mm-y;qq=y-nn;
				}
			}else if(nn==y){
				if(mm==x){
					pp=mm-z;qq=z-nn;
				}else{
					pp=mm-x;qq=x-nn;
				}
			}else{
				if(mm==y){
					pp=mm-x;qq=x-nn;
				}else{
					pp=mm-y;qq=y-nn;
				}
			}
			e[i].id=i;
			e[i].r1=max(pp,qq);
			e[i].r2=min(qq,pp);
		} 
		sort(e+1,e+1+n,cmp);
		for(int i=1;i<=n;i++){
			int id=e[i].id;
			if(vis[id]) continue;
			int r1=e[i].r1,r2=e[i].r2;
			int a=e[i].a,b=e[i].b,c=e[i].c;
			int nn=min(a,min(b,c));
			int mm=max(a,max(b,c));
			int oo;int t;int ff1=0,ff2=0,ff3=0;
			
			if(mm==a){
				if(nn==b){
					oo=c;
				}else oo=b;
			}else if(mm==b){
				if(nn==c){
					oo=a;
				}else oo=c;
			}else{
				if(nn==a){
					oo=b;
				}else oo=a;
			}
			
			if(r1==mm-oo){
				if(mm==a){
					t=1;
				}else if(mm==b){
					t=2;
				}else{
					t=3;
				}
				ff1=1;
			}else{
				if(oo==a){
					t=1;
				}else if(oo==b){
					t=2;
				}else{
					t=3;
				}
			}
			int flag=6;
			if(pd[t]<n/2){
				
				if(t==1) ans+=a;
				else if(t==2)ans+=b;
				else ans+=c;
				vis[id]=1;
				pd[t]++;
			}else{
				flag-=t;
				if(r2==mm-oo&&!ff1){
					if(mm==a){
						t=1;
					}else if(mm==b){
						t=2;
					}else{
						t=3;
					}
				}else{
					if(oo==a){
						t=1;
					}else if(oo==b){
						t=2;
					}else{
						t=3;
					}
				}
				if(pd[t]<n/2){
					
					if(t==1) ans+=a;
					else if(t==2)ans+=b;
					else ans+=c;
					vis[id]=1;
					pd[t]++;
				}else{
					flag-=t;
					pd[flag]++;
					if(flag==1) ans+=a;
					else if(flag==2)ans+=b;
					else ans+=c;
					vis[id]=1;
					pd[flag]++;
				}
			}
			
		}
		cout<<ans<<endl;
	}
	return 0;
} 
