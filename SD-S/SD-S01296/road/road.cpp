#include<bits/stdc++.h>
#define int long long
using namespace std;
int ksm(int a,int b,int p){
	int ans=1;
	while(b){
		if(b&1) ans=(ans*a)%p;
		b>>=1;a=(a*a)%p;
	}return ans;
}
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch-'0');ch=getchar();}
	return x*f;
}
struct nd{
	int u,v,w,id;
}e[2000005];
int dk[10005][15],bd[20],f[10005],us[20],ans=0,n,m,k,tt,cnt,Ans,sum;
int fd(int x){
	if(f[x]==x) return x;
	return f[x]=fd(f[x]);
}
bool cmp(nd aa,nd bb){
	return aa.w<bb.w;
}
bool cmp2(nd aa,nd bb){
	return aa.id<bb.id;
}
void sol1(){
//	cout<<"-------------------------------------\n";
	for(int i=1;i<=sum;i++){
		int u=e[i].u,v=e[i].v;
		int fu=fd(u),fv=fd(v);
		if(fu==fv) continue;
		int w=e[i].w;
		ans+=w;
//		cout<<u<<" "<<v<<" "<<w<<"\n";
		f[fv]=fu;
		cnt++;
		if(cnt==n) return;
	}
}
void sol2(){
	
}
void dfs(int cc){
	us[cc]=1;
	if(cc==k){
		ans=0,cnt=0,sum=m;
		for(int i=1;i<=n;i++) f[i]=i;
		for(int i=1;i<=k;i++){
			if(us[i]){
				ans+=bd[i];
				for(int j=1;j<=n;j++){
					sum++;
					e[sum]={j,n+i,dk[j][i],sum};
				}
			}
		}
		sort(e+1,e+1+sum,cmp);
		sol1();
		Ans=min(ans,Ans);
		sort(e+1,e+1+sum,cmp2);
	}
	else dfs(cc+1);
	us[cc]=0;
	if(cc==k){
		ans=0,cnt=0,sum=m;
		for(int i=1;i<=n;i++) f[i]=i;
		for(int i=1;i<=k;i++){
			if(us[i]){
				ans+=bd[i];
				for(int j=1;j<=n;j++){
					sum++;
					e[sum]={j,i,dk[j][i],sum};
				}
			}
		}
		sort(e+1,e+1+sum,cmp);
		sol1();
		Ans=min(ans,Ans);
		sort(e+1,e+1+sum,cmp2);
	}
	else dfs(cc+1);
}
void sol(){
	n=read(),m=read(),k=read(),tt=0,cnt=0,ans=0,Ans=1e18,sum=m;
	for(int i=1;i<=m;i++){
		e[i].u=read();
		e[i].v=read();
		e[i].w=read();
		e[i].id=i;
	}
	for(int i=1;i<=k;i++){
		bd[i]=read();
		tt+=bd[i];
		for(int j=1;j<=n;j++) dk[j][i]=read();
	}
	sort(e+1,e+1+m,cmp);
	if(k==0){
		for(int i=1;i<=n;i++) f[i]=i;
		sol1();
		cout<<ans;
	}
	else{
		dfs(1);
		cout<<Ans;
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int T=1;
//	T=read();
	while(T--) sol();
	return 0;
}
