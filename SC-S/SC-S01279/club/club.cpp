#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int n,t,ans,uu;
int vis[3],bm[3];
int a[N][3];
struct node{
	int mx,mn,md,id,z;
}b[N];
priority_queue<node>q[3];
bool operator <(node a,node b){
	return a.z>b.z;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		uu=n/2;
		ans=0;
		memset(vis,0,sizeof(vis));
		while(!q[0].empty())q[0].pop();
		while(!q[1].empty())q[1].pop();
		while(!q[2].empty())q[2].pop();
		memset(bm,0,sizeof(bm));
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			int mx=-1;
			b[i].id=i;
			for(int j=0;j<3;j++){
				if(a[i][j]>mx){
					b[i].mx=j;
					mx=a[i][j];
				}
			}
			mx=-1;
			for(int j=0;j<3;j++){
				if(a[i][j]>mx&&b[i].mx!=j){
					b[i].md=j;
					mx=a[i][j];
				}
			}
			for(int j=0;j<3;j++){
				if(b[i].md!=j&&b[i].mx!=j){
					b[i].mn=j;
				}
			}//cout<<b[i].md<<" "<<b[i].mx<<" "<<t<<"|"<<'\n';
			b[i].id=i;b[i].z=a[i][b[i].mx]-a[i][b[i].md]; 
			ans+=a[i][b[i].mx];
			q[b[i].mx].push(b[i]);
			bm[b[i].mx]++;
		}
		int cl1=0,cl2=0;
		for(int i=0;i<3;i++){
			if(bm[i]>uu){
				cl1=i;
				vis[i]=1;
				break;
			}
		}
//		cout<<bm[cl1];
		while(bm[cl1]>uu){
			
			node u=q[cl1].top();
			q[cl1].pop();//cout<<u.md<<" "<<u.mx<<" "<<u.id<<"|"<<'\n';
			ans-=a[u.id][cl1];
			bm[cl1]--;
			ans+=a[u.id][u.md];
			u.z=a[u.id][u.md]-a[u.id][u.mn];
			q[u.md].push(u);
			bm[u.md]++;
		}
		for(int i=0;i<3;i++){
			if(bm[i]>uu&&vis[i]==0){
				cl1=i;
				vis[i]=1;
				break;
			}
		}
		for(int i=0;i<3;i++){
			if(vis[i]==0){
				cl2=i;
				vis[i]=1;
				break;
			}
		}
		while(bm[cl1]>uu){
			node u=q[cl1].top();
			q[cl1].pop();
			ans-=a[u.id][cl1];bm[cl1]--;
			ans+=a[u.id][cl2];
		}
		cout<<ans<<'\n';
	}
	
	
	return 0;
	}
