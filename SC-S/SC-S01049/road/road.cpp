#include<bits/stdc++.h>
using namespace std;
long long n,m,k,hd[2000017],idx,f[10017];
struct edge{
	long long u,v,w;
}e[2000017];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
long long find(long long x){
	return f[x]==x?x:f[x]=find(f[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
//	if(k==0){
		for(int i=1;i<=n;i++){
			f[i]=i;
		}
		for(int i=1;i<=m;i++){
			cin>>e[i].u>>e[i].v>>e[i].w;
		}
		sort(e+1,e+m+1,cmp);
		long long cnt=0,t=0,ans=0;
		while(1){
			t++;
			long long l=e[t].u,r=e[t].v,val=e[t].w;
			long long fl=find(l),fr=find(r);
			if(fl!=fr){
				f[fl]=fr;
				cnt++;
				ans+=val;
			}
			if(cnt>=n-1){
				break;
			}
		}
		cout<<ans<<endl;
//	}
//	for(int i=1;i<=m;i++){
//		long long u,v,w;
//		cin>>a>>b>>c
//	}
	return 0;
}