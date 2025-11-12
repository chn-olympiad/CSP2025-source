#include<bits/stdc++.h>
#define F(i,a,b) for(int i=a;i<=b;i++)
#define R(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
typedef long long ll;
const ll N=2e6+7;
ll n,m,k,cnt,fa[N],cntne,ans,precntne,cntne2,cntne3,c[20],a[20][N],nowid;
struct edge{
	int u,v,w;
}e[N],ne[N],ne2[N],ne3[N],ne4[N];
inline ll fr(){
	ll s=0,k=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') k=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=(s<<3)+(s<<1)+ch-'0';
		ch=getchar();
	}
	return s*k;
}
inline bool cmp(edge a,edge b){
	return a.w<b.w;
}
inline void fw(ll x){
	if(x>9) fw(x/10);
	putchar((x%10)+'0');
}
inline int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
inline void kruskal1(){
	sort(e+1,e+m+1,cmp);
	F(i,1,n){
		fa[i]=i;
	}
	ll tot=0;
	F(i,1,m){
		int fx=find(e[i].u),fy=find(e[i].v);
		if(fx==fy) continue;
		fa[fx]=fy;
		tot++;
		ans+=e[i].w;
		ne[++cntne]=e[i];
		if(tot==n-1){
			break ;
		}
	}
//	cout<<ans<<"\n";
}
inline void kruskal2(){
	F(i,1,nowid){
		fa[i]=i;
	}
	ll tot=0,sum=0;
//	cout<<"WORK!:\n";
	F(i,1,cntne){
		int fx=find(ne[i].u),fy=find(ne[i].v);
//		cout<<ne[i].u<<" "<<ne[i].v<<" "<<fx<<" "<<fy<<"\n";
		if(fx==fy) continue;
		fa[fx]=fy;
		tot++;
		sum+=ne[i].w;
		if(tot==nowid-1){
			break ;
		}
	}
	ans=min(ans,sum);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	F(i,1,m){
		int from,to,w;
		cin>>from>>to>>w;
		e[++cnt].u=from;
		e[cnt].v=to;
		e[cnt].w=w;
	}
	F(i,1,k){
		cin>>c[i]; 
		F(j,1,n){
			cin>>a[i][j];
		}
	}
	kruskal1();
	F(i,1,cntne){
		ne4[i]=ne[i];
	}
	precntne=cntne;
	F(i,1,(1<<k)-1){
		nowid=n;
		cntne=precntne;
		cntne2=0;
		cntne3=0;
		F(j,1,cntne){
			ne[j]=ne4[j];
		}
		F(j,1,k){
			if((i>>(j-1))&1==1){
				nowid++;
				F(z,1,n){
					ne2[++cntne2].u=z;
					ne2[cntne2].v=nowid;
					ne2[cntne2].w=a[j][z];
				}
				nowid++;
				ne2[++cntne2].u=nowid-1;
				ne2[cntne2].v=nowid;
				ne2[cntne2].w=c[j];
			}
		}
		sort(ne2+1,ne2+cntne2+1,cmp);
		int now1=1,now2=1,now3=0;
		while(now1<=cntne&&now2<=cntne2){
			if(ne[now1].w<ne2[now2].w){
				ne3[++now3]=ne[now1];
				now1++;
			}
			else{
				ne3[++now3]=ne2[now2];
				now2++;
			}
		}
		while(now1<=cntne){
			ne3[++now3]=ne[now1++];
		}
		while(now2<=cntne2){
			ne3[++now3]=ne2[now2++];
		}
		int cntne3=now3;
//		cout<<"status:"<<i<<"\n";
		F(j,1,cntne3){
			ne[j]=ne3[j];
//			cout<<ne[j].u<<" "<<ne[j].v<<" "<<ne[j].w<<"\n";
		}
		cntne=cntne3;
		kruskal2();
	}
	cout<<ans<<"\n";
	return 0;
}
