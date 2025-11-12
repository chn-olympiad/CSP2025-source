#include<bits/stdc++.h>
#define int long long
using namespace std;
int n ,m ,k;
int vi[10001],c[15],a[15][10001];
vector<int> va[10001],vb[10001],vc[10001],vd[10001];
inline int dj(int zc){
	int s=0;
	priority_queue<pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int> > >q;
	q.push(make_pair(0,zc));
	while(!q.empty()){
		while(!q.empty()&&vi[q.top().second]==1)q.pop();
		if(q.empty())break;
		int uu=q.top().second;
//		cout<<uu<<"\n";
		vi[uu]=1;
		s+=q.top().first;
		q.pop();
		for(int i=0;i<va[uu].size();i++){
			int vv=va[uu][i],ww=vb[uu][i];
			if(!vi[vv]){
				q.push(make_pair(ww,vv));
				
			}
		} 
	}
	return s;
}
inline bool pd(){
	for(int i=1;i<=k;i++){
		if(c[i]!=0)return false;
	}return true;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u;
	for(int i=1,v,w;i<=m;i++){
		cin>>u>>v>>w;
		va[u].push_back(v);
		vb[u].push_back(w);
		va[v].push_back(u);
		vb[v].push_back(w);
	}
	if(k==0){
		cout<<dj(u);return 0;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}for(int i=1;i<=n;i++){
		vc[i]=va[i];
		vd[i]=vb[i];
	}
	if(pd()){
		for(int j=1;j<=n;j++)
		for(int h=1;h<=n;h++){
			if(j==h)continue;
			int minn=pow(2,60);
			for(int i=1;i<=k;i++){
				minn=min(minn,a[i][j]+a[i][h]);
			}
			va[j].push_back(h);
			vb[j].push_back(minn);
			va[h].push_back(j);
			vb[h].push_back(minn);
		}
		cout<<dj(u);
	}
	else{
		int minnn=pow(2,60);
		for(int bm=0;bm<=((1<<k)-1);bm++){
			memset(vi,0,sizeof vi);
			int ss=0;
			for(int i=1;i<=k;i++){
					if((bm>>(i-1))&1){
						ss+=c[i];
					}
						
				}
			for(int j=1;j<=n;j++)
			for(int h=1;h<=n;h++){
				if(j==h)continue;
				
				int minn=pow(2,60);
				for(int i=1;i<=k;i++){
					if((bm>>(i-1))&1){
						minn=min(minn,a[i][j]+a[i][h]);
					}
						
				}
				va[j].push_back(h);
				vb[j].push_back(minn);
				va[h].push_back(j);
				vb[h].push_back(minn);
			}
			minnn=min(minnn,dj(u)+ss);
			for(int i=1;i<=n;i++){
				va[i]=vc[i];
				vb[i]=vd[i];
			}
		}
		cout<<minnn;
	}
	return 0;
}


//64
