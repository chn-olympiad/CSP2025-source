#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
inline int read();
std::vector<std::pair <std::pair<int,int>,int> >cho,prepare;
int fir[20005];
int mnn[20005];
int fa[20005];
int nxt[3000005];
int v[3000005];
int w[3000005];
int c[15];
int a[15][10005];
int best[20005];
bool choose[20005];
int now=1;
std::vector<int>to[15];
void add(int x,int y,int z){
	if(x==y){
		return ;
	}
	v[++now]=y;
	w[now]=z;
	nxt[now]=fir[x];
	fir[x]=now;
	return ;
}
int getfa(int x){
	return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
long long mintree(int n,int firr=1){
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	cho.clear();
	std::vector<std::pair<int,std::pair<int,int> > >qu;
	for(int i=2;i<=now;i+=2){
		if(v[i]<=n&&v[i^1]<=n){
			qu.push_back({w[i],{v[i],v[i^1]}});
		}
	}
	long long ans=0;
	std::sort(qu.begin(),qu.end());
	for(int i=0;i<qu.size();i++){
		if(getfa(qu[i].second.first)!=getfa(qu[i].second.second)){
			fa[getfa(qu[i].second.first)]=getfa(qu[i].second.second);
			cho.push_back({{std::min(qu[i].second.first,qu[i].second.second),std::max(qu[i].second.first,qu[i].second.second)},qu[i].first});
			ans+=qu[i].first;
		}
	}
	std::sort(cho.begin(),cho.end());
	return ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n=read();
	int m=read();
	int k=read();
	for(int i=1;i<=n+k;i++){
		fir[i]=-1;
	}
	prepare.clear();
	for(int i=1;i<=m;i++){
		int x=read();
		int y=read();
		int z=read();
		add(x,y,z);
		add(y,x,z);
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		to[i].clear();
		for(int j=1;j<=n;j++){
			a[i][j]=read();
			add(n+i,j,a[i][j]);
			add(j,n+i,a[i][j]);
		}
	}
	long long ans1=mintree(n+k);
	auto cho2=cho;
	long long ans2=mintree(n);
	for(int i=0;i<cho2.size();i++){
		if(cho2[i].first.second>n){
			to[cho2[i].first.second-n].push_back(cho2[i].first.first);
		}
	}
	for(int i=1;i<=k;i++){
		ans1+=c[i];
	}
	for(int i=0;i<cho.size();i++){
		if(*std::lower_bound(cho2.begin(),cho2.end(),cho[i])!=cho[i]){// prepare for deleting
			prepare.push_back(cho[i]);
		}
	}
	long long rans=0x3f3f3f3f3f3f3f3f;
	for(int sta=0;sta<(1<<k);sta++){
		long long curans=ans1;
		for(int i=1;i<=n+k;i++){
			fa[i]=i;
		}
		for(int i=0;i<cho2.size();i++){
			if(cho2[i].first.second<=n){
				fa[getfa(cho2[i].first.first)]=getfa(cho2[i].first.second);
			}else{
				if(!(sta&(1<<(cho2[i].first.second-n-1)))){
					fa[getfa(cho2[i].first.first)]=getfa(cho2[i].first.second);
				}else{
					curans-=cho2[i].second;
				}
			}
		}
		now=1;
		for(int i=1;i<=n+k;i++){
			fir[i]=-1;
		}
		for(int i=1;i<=k;i++){
			if(sta&(1<<(i-1))){
				curans-=c[i];
			}else{
				for(int j=1;j<=n+k;j++){
					mnn[j]=0x3f3f3f3f;
				}
				for(int j=1;j<=n;j++){
					mnn[getfa(j)]=std::min(mnn[getfa(j)],a[i][j]);
				}
				for(int j=1;j<=n+k;j++){
					if(getfa(j)==j&&mnn[j]!=0x3f3f3f3f){
						add(j,getfa(i+n),mnn[j]);
						add(getfa(i+n),j,mnn[j]);
					}
				}
			}
		}
		for(int i=0;i<prepare.size();i++){
			add(getfa(prepare[i].first.first),getfa(prepare[i].first.second),prepare[i].second);
			add(getfa(prepare[i].first.second),getfa(prepare[i].first.first),prepare[i].second);
		}
		curans+=mintree(n+k,getfa(1));
		rans=std::min(rans,curans);
	}
	printf("%lld",rans);
	return 0;
}
inline int read(){
	int f=1,x=0;
	char temp=getchar();
	while(temp>'9'||temp<'0'){
		(temp=='-')?(f=-1):0;
		temp=getchar();
	}
	while('0'<=temp&&temp<='9'){
		x=(x<<3)+(x<<1)+(temp^'0');
		temp=getchar();
	}
	return f*x;
}