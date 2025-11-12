#include<bits/stdc++.h>
#define int long long
#define fup(a,b,c,d) for(int a=b;a<=c;a+=d)
#define fsf(a,b,c,d) for(int a=b;a>=c;a-=d)
#define pii pair<int,int>
#define ls (p<<1)
#define rs (p<<1|1)
using namespace std;
const int N=4e5+10;
const int INF=0x3f3f3f3f;
int T,n,m,ans;
struct Node{
	int val,id,bian;
	bool operator<(const Node &rhs)const{
		return val<rhs.val;
	}
};
int mp[N][4],vis[N],cnt[4],a[N];
void dfs(int pos,int sum){
	if(pos==n+1){
		ans=max(ans,sum);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		for(int j=1;j<=3;j++){
			if(j==1){
				if(cnt[1]==m)continue;
				else vis[i]=1,a[pos]=mp[i][j],cnt[1]++,dfs(pos+1,sum+mp[i][j]),cnt[1]--,vis[i]=0;
			} 
			if(j==2){
				if(cnt[2]==m)continue;
				else vis[i]=1,a[pos]=mp[i][j],cnt[2]++,dfs(pos+1,sum+mp[i][j]),cnt[2]--,vis[i]=0;
			}
			if(j==3){
				if(cnt[3]==m)continue;
				else vis[i]=1,a[pos]=mp[i][j],cnt[3]++,dfs(pos+1,sum+mp[i][j]),cnt[3]--,vis[i]=0;
			}
		} 
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>T;
	while(T--){
		memset(vis,0,sizeof vis);
		memset(cnt,0,sizeof cnt);
		ans=0;
		cin>>n;m=n/2;
		fup(i,1,n,1)cin>>mp[i][1]>>mp[i][2]>>mp[i][3];
		if(n<=30){
			dfs(1,0);
			cout<<ans<<'\n';	
		}
		else{
			cnt[1]=cnt[2]=cnt[3]=0;
			fup(i,1,n,1)vis[i]=0;
			priority_queue<Node>q; 
			fup(i,1,n,1){
				int a,b,c;
				a=mp[i][1];b=mp[i][2];c=mp[i][3];
				q.push({a,i,1});
				q.push({b,i,2});
				q.push({c,i,3});
			}
			while(q.size()){
				Node u=q.top();q.pop();
				if(vis[u.id])continue;
				if(cnt[u.bian]==n/2)continue;
				ans+=u.val;
				vis[u.id]=1;
				cnt[u.bian]++;
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
} 
