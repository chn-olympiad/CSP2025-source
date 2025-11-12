#include<bits/stdc++.h>
using namespace std;
long long t,f[100005];
struct Node{
	long long a,b,c,maxx;
}g[100005];
struct node{
	long long cha,id;
}p[100005];
bool cmp(node x,node y){
	return x.cha<y.cha;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--){
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
		memset(p,0,sizeof(p));
		long long n,A=0,B=0,C=0,ans=0;
		cin>>n;
		long long jx=n/2;
		for(int i=1;i<=n;i++){
			cin>>g[i].a>>g[i].b>>g[i].c;
			if(g[i].a>=g[i].b){
				if(g[i].a>=g[i].c){
					g[i].maxx=1;
					A++;
				}else{
					g[i].maxx=3;
					C++;
				}
			}else{
				if(g[i].b>=g[i].c){
					g[i].maxx=2;
					B++;
				}else{
					g[i].maxx=3;
					C++;
				}
			}
		}
		//cout<<A<<" "<<B<<" "<<C<<endl;
		if(A<=jx&&B<=jx&&C<=jx){
			for(int i=1;i<=n;i++){
				if(g[i].maxx==1){
					ans+=g[i].a;
				}else if(g[i].maxx==2){
					ans+=g[i].b;
				}else if(g[i].maxx==3){
					ans+=g[i].c;
				}
			}
		}else if(A>jx){
			long long cnt=0;
			for(int i=1;i<=n;i++){
				if(g[i].maxx==1){
					p[++cnt].cha=min(g[i].a-g[i].b,g[i].a-g[i].c);
					p[cnt].id=i;
				}
			}
			sort(p+1,p+cnt+1,cmp);
			for(int i=1;i<=A-jx;i++){
				ans+=max(g[p[i].id].b,g[p[i].id].c);
				f[p[i].id]=1;
			}
			for(int i=1;i<=n;i++){
				if(f[i]==0){
					if(g[i].maxx==1){
						ans+=g[i].a;
					}else if(g[i].maxx==2){
						ans+=g[i].b;
					}else if(g[i].maxx==3){
						ans+=g[i].c;
					}
				}
			}
		}else if(B>jx){
			long long cnt=0;
			for(int i=1;i<=n;i++){
				if(g[i].maxx==2){
					p[++cnt].cha=min(g[i].b-g[i].a,g[i].b-g[i].c);
					p[cnt].id=i;
				}
			}
			sort(p+1,p+cnt+1,cmp);
			for(int i=1;i<=B-jx;i++){
				ans+=max(g[p[i].id].a,g[p[i].id].c);
				f[p[i].id]=1;
			}
			for(int i=1;i<=n;i++){
				if(f[i]==0){
					if(g[i].maxx==1){
						ans+=g[i].a;
					}else if(g[i].maxx==2){
						ans+=g[i].b;
					}else if(g[i].maxx==3){
						ans+=g[i].c;
					}
				}
			}
		}else if(C>jx){
			long long cnt=0;
			for(int i=1;i<=n;i++){
				if(g[i].maxx==3){
					p[++cnt].cha=min(g[i].c-g[i].b,g[i].c-g[i].a);
					p[cnt].id=i;
				}
			}
			sort(p+1,p+cnt+1,cmp);
//			for(int i=1;i<=cnt;i++){
//				cout<<p[i].id<<endl;
//			}
			for(int i=1;i<=C-jx;i++){
				ans+=max(g[p[i].id].b,g[p[i].id].a);
				f[p[i].id]=1;
			}
			for(int i=1;i<=n;i++){
				if(f[i]==0){
					if(g[i].maxx==1){
						ans+=g[i].a;
					}else if(g[i].maxx==2){
						ans+=g[i].b;
					}else if(g[i].maxx==3){
						ans+=g[i].c;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
