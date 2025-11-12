#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n;
struct node{
	int x,id;
}a[N][4];
bool cmp(node a,node b){
	return a.x>b.x;
}
bool cmp1(int x,int y){
	return a[x][1].x-a[x][2].x>a[y][1].x-a[y][2].x;
}
int ori[4];
vector<int> g;
signed main(){
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		g.clear();
		memset(ori,0,sizeof ori);
		for(int i=1;i<=n;i++){
			cin>>a[i][1].x>>a[i][2].x>>a[i][3].x;
			a[i][1].id=1,a[i][2].id=2,a[i][3].id=3;
			g.push_back(i);
			sort(a[i]+1,a[i]+4,cmp);
		}
		sort(g.begin(),g.end(),cmp1);
		int ans=0;
		for(auto now:g){
		    if(ori[a[now][1].id]>=n/2){
		    	ans+=a[now][2].x;
		    	ori[a[now][2].id]++;
			}else{
				ans+=a[now][1].x;
				ori[a[now][1].id]++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

