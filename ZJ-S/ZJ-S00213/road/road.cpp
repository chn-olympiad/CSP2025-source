#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
struct E{
	int u,v,w;
}e[1919810];
int n,m,k,t,ans=0x7fffffffffffffff,flag,c[114],f[11450],ha=1;
int fd(int x){
	if(f[x]==x){
		return x;
	}
	f[x]=fd(f[x]);
	return f[x];
}
void mg(int a,int b){
	if(fd(a)!=fd(b)){
		f[fd(a)]=fd(b);
	}
//	cout<<a<<b<<endl;for(int i=1;i<=n+k;i++)cout<<fd(i);cout<<endl;
}
bool cmp(E a,E b){
	return a.w<b.w;
}
int mgt(int d){
	for(int i=1;i<=n+k;i++){
		f[i]=i;
	}
	int ret=0;
	for(int i=0,j=__builtin_popcount(d)+n;j>1&&i<m;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
//		cout<<u<<v<<w<<" ";
		if(fd(u)!=fd(v)&&(u<=n||d&(1<<(u-1-n)))){
			mg(u,v);
//			cout<<fd(u)<<fd(v)<<" ";
			ret+=w;
			j--;
//			cout<<ret<<" ";
		}
	}
//	for(int i=1;i<=n+k;i++)cout<<f[i]<<" ";
	return ret;
}
signed main(){
	ios::sync_with_stdio(false);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	
	for(int i=0;i<k;i++){
		cin>>c[i];
		if(c[i]){
			ha=0;
		}
		flag=0;
		for(int j=0;j<n;j++){
			e[m].u=i+n+1;
			e[m].v=j+1;
			cin>>e[m++].w;
			if(e[m-1].w==0){
				flag=1;
			}
		}
		if(!flag){
			ha=0;
		}
	}
//	for(int i=0;i<m;i++)cout<<e[i].u<<e[i].v<<e[i].w<<" ";cout<<endl;
	sort(e,e+m,cmp);
	
	if(ha){
		cout<<mgt((1<<k)-1);
	}else{
		for(int i=0;i<(1<<k);i++){
			t=mgt(i);
			for(int j=0;j<k;j++){
				if(i&(1<<j)){
					t+=c[j];
				}
			}
//			cout<<t<<endl;
			ans=min(ans,t);
		}
		cout<<ans;
	}
	return 0;
}

