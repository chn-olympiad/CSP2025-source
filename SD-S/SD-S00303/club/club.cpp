#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int inf=0x3f3f3f3f;
const int N=1e5+5,M=200+5;
int n,ans=0,c[3];
int f[2][M][M];
struct Person{
	int w[3],mx;
}a[N];
//struct Node{
//	int x,y,k;
//};
//bool operator<(const Node &x,const Node &y){return x.k<y.k;}
//priority_queue<Node>q,r;
//void solve(){
//	ans=0,full=-1;
//	c[0]=c[1]=c[2]=0;
//	while(!q.empty())q.pop();
//	while(!r.empty())r.pop();
//	cin>>n;
//	for(int i=1;i<=n;i++){
//		cin>>a[i].w[0]>>a[i].w[1]>>a[i].w[2];
//		int &x=a[i].mx;
//		for(int j=1;j<3;j++)
//			if(a[i].w[j]>a[i].w[x])x=j;
//	}
//	sort(a+1,a+n+1,[](const Person &x,const Person &y){return x.w[x.mx]>y.w[y.mx];});
//	for(int i=1;i<=n;i++){
//		int x=a[i].mx,y=-1;
//		for(int j=0;j<3;j++){
//			if(j==x)continue;
//			if(y==-1)y=j;
//			if(a[i].w[j]>a[i].w[y])y=j;
//		}
//		if(c[x]>=n/2){
//			full=x;
//			c[y]++;
//			ans+=a[i].w[y];
//			q.push(Node{y,x,a[i].w[x]-a[i].w[y]});
//			continue;
//		}
//		c[x]++;
//		ans+=a[i].w[x];
//	}
//	if(full==-1){
//		cout<<ans<<"\n";
//		return;
//	}
//	for(int i=1;i<=n;i++){
//		int x=a[i].mx;
//		if(full==x)continue;
//		r.push(Node{x,full,a[i].w[full]-a[i].w[x]});
//	}
//	while(!q.empty()&&!r.empty()&&q.top().k+r.top().k>0){
//		ans+=q.top().k+r.top().k;
//		q.pop(),r.pop();
//	}
//	cout<<ans<<"\n";
//}
//void dfs(int x,int w){
//	if(x>n){
//		ans=max(ans,w);
//		return;
//	}
//	for(int i=0;i<3;i++){
//		if(c[i]>=n/2)continue;
//		c[i]++;
//		dfs(x+1,w+a[x].w[i]);
//		c[i]--;
//	}
//}
bool fa=true;
void solve(){
	ans=0,fa=true;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++)
			cin>>a[i].w[j];
		if(a[i].w[1])fa=false;
		if(a[i].w[2])fa=false;
	}
	if(fa){
		for(int i=1;i<=n;i++)ans+=a[i].w[0];
		cout<<ans<<"\n";
		return;
	}
	int o=0;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			f[o][i][j]=-inf;
	f[o][0][0]=0;
	for(int i=1;i<=n;i++){
		o^=1;
		for(int j=0;j<=n;j++)
			for(int k=0;k<=n;k++)
				f[o][j][k]=-inf;
		for(int j=0;j<=n;j++)
			for(int k=0;k<=n;k++){
				if(j+1<=n/2)f[o][j+1][k]=max(f[o][j+1][k],f[o^1][j][k]+a[i].w[0]);
				if(k+1<=n/2)f[o][j][k+1]=max(f[o][j][k+1],f[o^1][j][k]+a[i].w[1]);
				if(0<=i-j-k&&i-j-k<=n/2)f[o][j][k]=max(f[o][j][k],f[o^1][j][k]+a[i].w[2]);
			}
	}
	for(int j=0;j<=n;j++)
		for(int k=0;k<=n;k++)
			ans=max(ans,f[o][j][k]);
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin>>T;
	while(T--)solve();
	return 0;
} 
