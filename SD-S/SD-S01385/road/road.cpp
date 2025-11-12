#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int N=1e4+100;
struct node{
	long long u=0,v=0,w=0;
}e[N*100],ne[N],f[20][N];
long long n,m,k,fa[N],ans,num,c[20],b[20],num1=0,zz[20],ans1,ww;
vector<node> G[N];
long long find(long long h){
	if(h==fa[h])return h;
	fa[h]=find(fa[h]);
	return fa[h];
}
bool cmp(node ax,node bx){
	if(ax.w<bx.w)return 1;
	return 0;
}
node reafind(int wi){
	node res=ne[wi];
	int resk=0;
	if(wi>num)res.w=1e9+10;
	for(int i=1;i<=num1;i++){
		if(f[b[i]][zz[b[i]]].w<res.w && zz[b[i]]<=n)res=f[b[i]][zz[b[i]]],resk=i;
	}
//	if(res.w==ne[wi].w && wi<=num){
//		ww++;
//		return res;
//	}
//	for(int i=1;i<=num1;i++){
//		if(f[b[i]][zz[b[i]]].w==res.w){
//			zz[b[i]]++;
//			return res;
//		}
//	}
	if(resk!=0)zz[b[resk]]++;
	else ww++; 
//	ww++;
	return res;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>f[i][j].w,f[i][j].v=j,f[i][j].u=n+i;
		sort(f[i]+1,f[i]+n+1,cmp);
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		long long fu=find(e[i].u),fv=find(e[i].v);
		if(fu==fv)continue;
		ne[++num]=e[i];
		ans+=e[i].w;
		fa[fu]=fv;
	}
	if(k==0){
		cout<<ans<<'\n';
		return 0; 
	}
	long long na=pow(2,k);
	for(int s=1;s<na;s++){
		num1=ans1=0;
		for(int i=1;i<=n+k;i++)fa[i]=i;
		for(int i=1,cc=1;i<na;i*=2,cc++){
			zz[cc]=1;
//			cout<<s<<' '<<i<<' '<<(s&i)<<'\n';
			if((s&i)!=0)b[++num1]=cc,ans1+=c[cc];
		}
//		cout<<'\n';
//		cout<<num1<<' ';
		ww=1;
		for(int i=1;i<=num+num1*n;i++){
			node minn=reafind(ww);
			long long fu=find(minn.u),fv=find(minn.v);
			if(fu==fv)continue;
			ans1+=minn.w;
			fa[fu]=fv;
		}
//		cout<<s<<' '<<ans1<<'\n';
		ans=min(ans,ans1);
	}
	cout<<ans<<'\n';
	return 0;
}
