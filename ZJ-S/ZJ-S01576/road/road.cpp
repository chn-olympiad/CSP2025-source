#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int ret=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9'){
		ret=ret*10+c-'0';
		c=getchar();
	}
	return ret;
}
inline void write(int x){
	if(x==0){
		putchar('0');
		return;
	}
	char buf[22];
	int idx=0;
	while(x){
		buf[idx++]=x%10+'0';
		x/=10;
	}
	while(idx--) putchar(buf[idx]);
}
const int MAXN=10105,MAXK=13;
int n,m,k,u,v,w,a[MAXK],fa[MAXN],ans,cnt,an,ok,aaa;
bool flag[MAXK];
struct edge{
	int u,v,w;
};
vector<edge> mp;
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	mp.reserve(m+(k*n));
	for(int i=1;i<=m;i++){
		u=read();
		v=read();
		w=read();
		mp.push_back({u,v,w});
	}
	sort(mp.begin(),mp.end(),[](edge i,edge j){return i.w<j.w;});
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=0;i<m;i++){
		int x=find(mp[i].u),y=find(mp[i].v);
		if(x==y) continue;
		ans+=mp[i].w;
		fa[x]=y;
		cnt++;
		if(cnt==n-1) break;
	}
//	cout<<ans<<'\n';
	for(int o=1;o<=k;o++){
		a[o]=read();
		an+=a[o];
//		mp.reserve(m+(o*n));
		for(int j=1;j<=n;j++){
			mp.push_back({n+o,j,read()});
		}
		ok++;
		stable_sort(mp.begin(),mp.end(),[](edge i,edge j){return i.w<j.w;});
		flag[o]=1;
		for(int i=1;i<=n+o;i++) fa[i]=i;
		aaa=cnt=0;
		for(int i=0;i<m+(o*n);i++){
			if(mp[i].u>n&&!flag[mp[i].u-n]) continue;
			int x=find(mp[i].u),y=find(mp[i].v);
			if(x==y) continue;
			aaa+=mp[i].w;
			fa[x]=y;
			cnt++;
//			cout<<mp[i].u<<' '<<mp[i].v<<' '<<cnt<<' '<<n+ok-1<<'\n';
			if(cnt==n+ok-1) break;
		}
		if(aaa+an<ans){
			ans=aaa+an;
		}
		else{
			ok--;
			flag[o]=0;
			an-=a[o];
		}
//		cout<<ans<<'\n';
	}
	write(ans);
	return 0;
}
