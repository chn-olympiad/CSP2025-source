#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

struct edge{
	int x,y,z;
	friend bool operator<(edge x,edge y){
		return x.z<y.z;
	}
	friend bool operator>(edge x,edge y){
		return x.z>y.z;
	}
}e[2000010];

priority_queue<edge,vector<edge>,greater<edge> >q;

int fa[20010],c[16],cnt[16];

int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}

int main(){
    #ifndef Reimu
        freopen("road.in","r",stdin);
        freopen("road.out","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,k;cin>>n>>m>>k;
    for(int i=1;i<=m;i++)cin>>e[i].x>>e[i].y>>e[i].z;
    for(int i=1;i<=n;i++)fa[i]=i;
    sort(e+1,e+m+1);
    int tot=0;
    ll ans=0;
    for(int i=1;i<=m;i++){
    	if(tot==n-1)break;
    	int xx=find(e[i].x),yy=find(e[i].y);
    	if(xx==yy)continue;
    	fa[xx]=yy;
    	ans+=e[i].z;
    	q.push(e[i]);
    	tot++;
	}
	ll sum=0,ot=0;
	for(int i=1;i<=k;i++){
		cin>>c[i];
//		cerr<<ans<<' '<<c[i]<<"***\n";
		sum+=c[i];
		ll res=sum;
		int u=n+i,nn=n+i-ot;
		priority_queue<edge,vector<edge>,greater<edge> >qq=q,q1;
		for(int j=1;j<=n;j++){
			int x;cin>>x;
			q.push((edge){u,j,x});
		}
		tot=0;
		for(int j=1;j<=n+32;j++)fa[j]=j;
//		cerr<<q.size()<<'\n';
//		int cnt1=0;
		while(!q.empty()){
			edge ls=q.top();
			q.pop();
			if(tot==nn-1)break;
			int xx=find(ls.x),yy=find(ls.y);
//			if(ls.x<=n&&ls.y<=n&&xx==yy){
//				cnt1++;
//				cerr<<ls.x<<' '<<ls.y<<' '<<xx<<' '<<yy<<'\n';
//			}
			if(xx==yy)continue;
//			if(ls.x>n||ls.y>n)cerr<<ls.x<<' '<<ls.y<<"***\n";
			res+=ls.z;
			q1.push(ls);
			fa[xx]=yy;
//			if(yy==151)cerr<<ls.x<<' '<<ls.y<<"---\n";
			tot++;
		}
//		cerr<<ans<<' '<<res<<' '<<tot<<' '<<nn<<' '<<cnt1<<'\n';
		if(res<ans){
			ans=res;
			q=q1;
		}
		else {
			q=qq;
			ot++;
			sum-=c[i];
			continue;
		}
		memset(cnt,0,sizeof(cnt));
		qq=q;
		while(!q.empty()){
			int xx=q.top().x,yy=q.top().y;
			if(xx>n)cnt[xx-n]++;
			if(yy>n)cnt[yy-n]++;
			q.pop();
		}
		for(int j=1;j<=i;j++){
			if(cnt[j]==1){
				ans-=c[j];
				sum-=c[j];
				ot++;
//				cerr<<ot<<' '<<j<<'\n';
			}
		}
		while(!qq.empty()){
			int xx=qq.top().x,yy=q.top().y;
			bool flag=0;
			if(xx>n&&cnt[xx-n]==1){
				ans-=qq.top().z;
				flag=1;
			}
			if(yy>n&&cnt[yy-n]==1){
				ans-=qq.top().z;
				flag=1;
			}
			if(!flag)q.push(qq.top());
			qq.pop();
		}
	}
//	cerr<<sum<<'\n';
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

*/