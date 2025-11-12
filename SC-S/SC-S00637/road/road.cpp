#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int ret=0,op=1;char in=getchar();
	while(!isdigit(in)){if(in=='-'){op=-1;}in=getchar();}
	while(isdigit(in)){ret=(ret<<3)+(ret<<1)+(in^48);in=getchar();}
	return ret*op;
}
int dotc,linc,knum,val[20];
pair<int,int> arr[20][10010];int ret;//=1e10;
int pre[10010];set<pair<int,int> >st;
int dis2[20];
vector<pair<int,int> > lin[10010];
tuple<int,int,int> lins[1000010];
bool cmp(tuple<int,int,int> x,tuple<int,int,int> y){
	return (get<2>(x))<(get<2>(y));
}
int get(int x){
	if(pre[x]==x)return x;
	return pre[x]=get(pre[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	dotc=read();linc=read();knum=read();
	for(int i=1;i<=dotc;i+=1)pre[i]=i;
	for(int i=1;i<=linc;i+=1){
		int x=read(),y=read(),l=read();
		lins[i]=make_tuple(x,y,l);
	}
	for(int i=1;i<=knum;i+=1){
		val[i]=read();
		for(int j=1;j<=dotc;j+=1){
			arr[i][j]={read(),j};
		}
	}
	sort(lins+1,lins+linc+1,cmp);
	int tot=0;
	for(int i=1;i<=linc;i+=1){
		int u=get<0>(lins[i]);
		int v=get<1>(lins[i]);
		int l=get<2>(lins[i]);
	    int x=get(u),y=get(v);
		if(x!=y){
			tot+=1;pre[x]=y;
			ret+=l;//dis[i]=1;
		    lin[u].push_back({v,l});
			lin[v].push_back({u,l});
		}
		if(tot==dotc-1)break;
		if(1.0*clock()/CLOCKS_PER_SEC>=0.9){
			printf("%lld",ret);
			return 0;
		}
	}
	for(int i=1;i<=dotc;i+=1){
		for(int j=lin[i].size()-1;j>=0;j-=1){
			int len=lin[i][j].second;
			int suc=lin[i][j].first;
			if(st.find({i,suc})!=st.end()){
				continue;
			}
			int p=0,mx=INT_MIN*10000LL;
			for(int k=1;k<=knum;k+=1){
				int now=val[k]+arr[k][i].first;
				now+=arr[k][suc].first;
				if(mx<len-now)mx=len-now,p=k;
			}
			if(p!=0){
				if(mx>=0){
					ret-=mx;
					st.insert({suc,i});
					ret-=dis2[p];
					dis2[p]=0;
					arr[p][i].first=0;
					arr[p][suc].first=0;
					val[p]=0;
				}
				else if(val[p]+mx>0)dis2[p]+=val[p]-mx;
			}
			if(1.0*clock()/CLOCKS_PER_SEC>=0.9){
				printf("%lld",ret);
				return 0;
			}
		}
	}
	printf("%lld",ret);
	return 0;
}