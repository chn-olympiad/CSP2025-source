#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e4+5,M=3e6+5;
int n,m,k,head[N],tot,build[15][N],c[N],ans=1e9,vis[N],ohead[N],f=1;
struct node{
	int to,nxt,ver;
}tu[M];
void add(int x,int y,int z){
	tu[++tot].nxt=head[x];
	head[x]=tot;
	tu[tot].to=y;
	tu[tot].ver=z;
}
int chack(){
	int sum=0,cnt=0;
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	q.push(make_pair(0,1));
	while(!q.empty()){
		int x=q.top().second;
		if(vis[x]){
			q.pop();
			continue;
		}
		sum+=q.top().first;
		q.pop();
		vis[x]=1;
		for(int i=head[x];i;i=tu[i].nxt){
			cnt++;
			int w=tu[i].ver,y=tu[i].to;
			if(vis[y]) continue;
			//cout<<"haha";
			q.push(make_pair(w,y));
		}
	}
	//cout<<cnt<<endl;
	return sum;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		add(x,y,z);
		add(y,x,z); 
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0) f=0;
		//cout<<i<<endl;
		for(int j=1;j<=n;j++){
			scanf("%lld",&build[i][j]);
			//cout<<j<<" "<<build[i][j]<<endl;
		}
		//cout<<endl;
	}
	if(f){
		int xin=0;
		for(int ccnt=0;ccnt<k;ccnt++){
			xin++;
			for(int j=1;j<=n;j++){
				add(n+xin,j,build[ccnt+1][j]);
				add(j,n+xin,build[ccnt+1][j]);
			}
		}
		cout<<chack();
		return 0;
	}
	int p=(1<<k)-1;
	for(int i=0;i<=p;i++){
		//cout<<i<<endl;
		for(int j=1;j<=n+k;j++) vis[j]=0;
		int od=tot;
		for(int j=1;j<=n+k;j++) ohead[j]=head[j];
		int cnt=0,xin=0;
		int op=i,ccnt=0;
		while(op){
			if(op&(1<<ccnt)){
				xin++;
				for(int j=1;j<=n;j++){
					add(n+xin,j,build[ccnt+1][j]);
					add(j,n+xin,build[ccnt+1][j]);
				}
				cnt+=c[ccnt+1],op-=(1<<ccnt);
			}
			ccnt++;
		}
		cnt+=chack();
		//cout<<xin<<endl;
		ans=min(ans,cnt);
		for(int j=1;j<=n+k;j++) head[j]=ohead[j];
		tot=od;
	}
	cout<<ans;
	return 0;
}
