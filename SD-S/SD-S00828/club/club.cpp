#include <bits/stdc++.h>
#define int long long
#define JTB ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
const int MAXN=1e5+10;
int T,n,sum,a[MAXN][4],vis[MAXN];
struct Node{
	int id,val;
	bool operator < (const Node &rhs )const {
		return val<rhs.val;
	}
};
signed main(){
	JTB
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));
		priority_queue<Node>pt1;
		priority_queue<Node>pt2;
		priority_queue<Node>pt3;for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			sum+=a[i][2];
			sum+=a[i][3];
		}	
		for(int i=1;i<=n;i++){
			pt1.push({i,a[i][1]});
			pt2.push({i,a[i][2]});
			pt3.push({i,a[i][3]});
		}
		int cnt=0,ans=0,sum1=0,sum2=0,sum3=0;
		if(sum==0){
			while(cnt<n/2){
				ans+=pt1.top().val;
				pt1.pop();
				cnt++;
			}
		}
		else while(cnt<n){
			if(pt1.size()){
				if(pt2.empty()||pt1.top().val>=pt2.top().val){
					if(pt3.empty()||pt1.top().val>=pt3.top().val){
						if(sum1<(n/2)&&vis[pt1.top().id]==0){
							ans+=pt1.top().val;
							vis[pt1.top().id]=1;
							cnt++;
							sum1++;
						}
						pt1.pop();
					}
				}
			}
			if(pt2.size()){
				if(pt1.empty()||pt2.top().val>=pt1.top().val){
					if(pt3.empty()||pt2.top().val>=pt3.top().val){
						if(sum2<(n/2)&&vis[pt2.top().id]==0){
							ans+=pt2.top().val;
							vis[pt2.top().id]=1;
							cnt++;
							sum2++;
						}
						pt2.pop();
					}
				}
			}
			if(pt3.size()){
				if(pt2.empty()||pt3.top().val>=pt1.top().val){
					if(pt1.empty()||pt3.top().val>=pt2.top().val){
						if(sum3<(n/2)&&vis[pt3.top().id]==0){
							ans+=pt3.top().val;
							vis[pt3.top().id]=1;
							cnt++;
							sum3++;
						}
						pt3.pop();
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
