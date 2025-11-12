#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,x,y,z,c[15],a[15][20005],fal=1e18,tot,ans,op,qi[15],top,b[20005][5],fa[20005],s[15];bool v[20005];
struct zcx{
	ll x,y,z;
	bool operator<(const zcx&ui)const{return z>ui.z;}
};
priority_queue<zcx>q;
inline ll find(ll x){
	if(fa[x]==x){return x;}
	return fa[x]=find(fa[x]);
}
inline void add(ll x,ll y,ll z){q.push({x,y,z});}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&b[i][1],&b[i][2],&b[i][3]);
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){scanf("%lld",&a[i][j]);}
		a[i][x=0]=1e18;
		for(int j=1;j<=n;j++){if(a[i][j]<a[i][x]){x=j;}}
		qi[i]=x;
	}
	if(k==0){
		for(int j=1;j<=n;j++){v[j]=false;fa[j]=j;}
		for(int j=1;j<=m;j++){add(b[j][1],b[j][2],b[j][3]);add(b[j][2],b[j][1],b[j][3]);}
		while(!q.empty()){
			ll nx=q.top().x,ny=q.top().y,nw=q.top().z;q.pop();
			if(find(nx)==find(ny)){continue;}
			ans+=nw;fa[ny]=nx;
		}
		printf("%lld",ans);
	}
	else if(k<=5){
		z=pow(2,k);
		for(int i=0;i<z;i++){
			x=i;top=0;ans=0;
			for(int j=1;j<=n;j++){v[j]=false;fa[j]=j;}
			for(int j=1;j<=m;j++){add(b[j][1],b[j][2],b[j][3]);add(b[j][2],b[j][1],b[j][3]);}
			while(x){s[++top]=x%2;x>>=1;}
			for(int j=1;j<=k;j++){
				if(s[j]){
					ans+=c[j]+a[j][qi[j]];
					for(int w=1;w<=n;w++){
						if(w!=qi[j]){add(qi[j],w,a[j][w]);add(w,qi[j],a[j][w]);}
					}
				}
			}
			while(!q.empty()){
				ll nx=q.top().x,ny=q.top().y,nw=q.top().z;q.pop();
				if(find(nx)==find(ny)){continue;}
				ans+=nw;fa[ny]=nx;
			}
			fal=min(fal,ans);
		}
		printf("%lld",fal);
	}
	else{
		for(int j=1;j<=n;j++){v[j]=false;fa[j]=j;}
		for(int j=1;j<=m;j++){add(b[j][1],b[j][2],b[j][3]);add(b[j][2],b[j][1],b[j][3]);}
		for(int j=1;j<=k;j++){	
			ans+=c[j]+a[j][qi[j]];
			for(int w=1;w<=n;w++){
				if(w!=qi[j]){add(qi[j],w,a[j][w]);add(w,qi[j],a[j][w]);}
			}
		}
		while(!q.empty()){
			ll nx=q.top().x,ny=q.top().y,nw=q.top().z;q.pop();
			if(find(nx)==find(ny)){continue;}
			ans+=nw;fa[ny]=nx;
		}	
		printf("%lld",ans);
	}
	return 0;
}
