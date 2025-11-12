#include<bits/stdc++.h>
#define pil pair<long long,pair<int,int> >
#define fir first
#define sec second
using namespace std;
const int mapo=1e4+20;
int n,m,k,kn,p[15],fa[mapo];
long long used[15],sum=0,ans=0;
priority_queue<pil,vector<pil>,greater<pil> >qu[15];
int fifa(int x){
	if(fa[x]==x)return x;
	return fa[x]=fifa(fa[x]);
}
void f(){
	while(sum<kn-1){
		//cout<<ans<<" ";
//		for(int i=1;i<=6;i++)cout<<fa[i]<<" ";
//		cout<<"\n";
		long long mi=1e18;
		int fl=-1;
		for(int i=0;i<=k;i++){
			if(!qu[i].empty()&&qu[i].top().fir+p[i]<mi){
				mi=qu[i].top().fir+p[i],fl=i;
			}
		}
		if(fl==-1)return ;
		pil now=qu[fl].top();
		int x=now.sec.fir,y=now.sec.sec;
		int fx=fifa(x),fy=fifa(y);
		if(p[fl])kn++;
		if(fl){
			if(used[fl]==0)used[fl]=mi;
			else used[fl]=-1;
		}
		qu[fl].pop(),p[fl]=0;
		//cout<<x<<" "<<y<<" "<<mi<<"\n";
		if(fx==fy)continue;
		sum++,fa[fx]=fy,ans=ans+mi;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		qu[0].push({z,{x,y}});
	}
	for(int i=1;i<=k;i++){
		cin>>p[i];
		for(int j=1;j<=n;j++){
			int x;
			cin>>x;
			qu[i].push({x,{n+i,j}});
		}
	}
	kn=n,f();
	for(int i=1;i<=k;i++){
		if(used[i]>0)ans-=used[i];
		//cout<<used[i]<<" ";
	}
	cout<<ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

4 3 4
4 2 5
1 4 6
2 3 7

1
5 1 1
5 3 2
5 4 4
5 2 8

100
6 1 1
6 3 2
6 2 3
6 4 4


4 3 4
4 2 5
1 4 6
2 3 7

1
5 1 1
5 3 2
5 4 4
5 2 8

100
6 1 1
6 3 2
6 2 3
6 4 4

4-2-3-5-1

5 1
5 3


*/