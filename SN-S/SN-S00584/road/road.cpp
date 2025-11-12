#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
//#define DBL
using namespace std;
const ll N=1e4+10;
int n,m,K,u,v,w,fa[N],tot=0,num;
ll ans=0,c[11][N],lw;
int findf(int x){
	if(fa[x]==x){
		return x;
	}
	fa[x]=findf(fa[x]);
	return fa[x];
}
struct roadd{
	int u,v,w;
	bool friend operator<(roadd a,roadd b){
		return a.w>b.w;
	}
}inn,bz[N];
priority_queue<roadd>q;
ll cl(int x){
	int tt=0;ll ret=0;
	while(x){
		if(x&1){
			num++;
			inn.u=num;
			for(int i=1;i<=n;i++){
				inn.v=i;
				inn.w=c[tt][i];
				q.push(inn);
			}
			ret+=c[tt][0];
		}
		x>>=1;tt++;
	}
	return ret;
}
void js(){
	for(int i=1;i<=num;i++){
		fa[i]=i;
	}
	num--;
	while(!q.empty()){
		inn=q.top();q.pop();
		int fu=findf(inn.u),fv=findf(inn.v);
		if(fu!=fv){
			lw+=inn.w;
			fa[fu]=fv;
			num--;
			if(!num){
				break;
			}
		}
	}
	return ;
}
template<typename Tpp>
void rd(Tpp &ret){
	ret=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		ret=ret*10+ch-'0';
		ch=getchar();
	}
	return ;
}
void wt(ll x){
	if(x>10){
		wt(x/10);
	}
	putchar(x%10+'0');
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	rd(n);rd(m);rd(K);
	for(int i=1;i<=m;i++){
		rd(inn.u);rd(inn.v);rd(inn.w);
		q.push(inn);
	}
	for(int i=0;i<K;i++){
		for(int j=0;j<=n;j++){
			rd(c[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	while(!q.empty()){
		inn=q.top();q.pop();
		int fu=findf(inn.u),fv=findf(inn.v);
		if(fu!=fv){
			ans+=inn.w;
			tot++;
			bz[tot]=inn;
			fa[fu]=fv;
			if(tot==n-1){
				break;
			}
		}
	}
	//return 0;
	int mxzt=1<<K;mxzt--;
	for(int zt=1;zt<=mxzt;zt++){
		while(!q.empty()){
			q.pop();
		}
		num=n;
		for(int i=1;i<=tot;i++){
			q.push(bz[i]);
		}
		lw=cl(zt);
		if(lw>=ans){
			continue;
		}
		js();
		ans=min(ans,lw);
	}
	//cout<<ans;
	wt(ans);
	return 0;
}

