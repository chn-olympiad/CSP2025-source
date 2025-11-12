#include <iostream>
#include <queue>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
const int N=1e5+5;
int T,n,a[N][3],b[N][3],cnt[3];
struct node{
	int x,y;
	bool operator<(const node& nd)const{
		//if (cnt[y]>n/2)return 0;
		return a[x][b[x][y]]-a[x][b[x][y+1]]>a[nd.x][b[nd.x][nd.y]]-a[nd.x][b[nd.x][nd.y+1]];
	}
};
priority_queue<node> q;
ll ans;
void solve(){
	cin>>n;
	cnt[0]=cnt[1]=cnt[2]=0;ans=0;
	while (q.size())q.pop();
	for (int i=1;i<=n;++i){
		for (int j=0;j<3;++j){
			cin>>a[i][j];
		}
		if (a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
			b[i][0]=0;
			if (a[i][1]>a[i][2])b[i][1]=1,b[i][2]=2;
			else b[i][1]=2,b[i][2]=1;
		}
		if (a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
			b[i][0]=1;
			if (a[i][0]>a[i][2])b[i][1]=0,b[i][2]=2;
			else b[i][1]=2,b[i][2]=0;
		}
		if (a[i][2]>=a[i][1]&&a[i][2]>=a[i][0]){
			b[i][0]=2;
			if (a[i][0]>a[i][1])b[i][1]=0,b[i][2]=1;
			else b[i][1]=1,b[i][2]=0;
		}
		cnt[b[i][0]]++;
		ans+=a[i][b[i][0]];
		q.push({i,0});
	}
	if (cnt[0]<=n/2&&cnt[1]<=n/2&&cnt[2]<=n/2){
		cout<<ans<<'\n';
		return;
	}
	else{
		while (q.size()&&(cnt[0]>n/2||cnt[1]>n/2||cnt[2]>n/2)){
			node p=q.top();q.pop();
			int x=p.x,y=p.y;
			if (cnt[b[x][y]]>n/2){
				ans-=a[x][b[x][y]]-a[x][b[x][y+1]];
				cnt[b[x][y]]--;cnt[b[x][y+1]]++;
				//if (y<2)q.push({x,y+1});
			}
		}
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>T;
	while (T--)solve();
	cout.flush();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
