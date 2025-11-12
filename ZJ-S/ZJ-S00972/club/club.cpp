#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100000+10;
int T,n,cnt[3];
vector<int> G;
struct node{
	int val,id;
	bool operator<(node &x)const{
		return val>x.val;
	}
}a[N][4];
void solve(){
	cnt[1]=cnt[2]=cnt[3]=0;
	G.clear();
	int ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j].val;
			a[i][j].id=j;
		}
		sort(a[i]+1,a[i]+4);
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=3;j++) cout<<a[i][j].val<<" ";
//		cout<<endl;
//	}
	for(int i=1;i<=n;i++){
		ans+=a[i][1].val;
		cnt[a[i][1].id]++;
	}
	int p=0;
	for(int i=1;i<=3;i++){
		if(cnt[i]>n/2){
			for(int j=1;j<=n;j++){
				if(a[j][1].id==i){
//					for(int j=1;j<=3;j++) cout<<a[i][j].val<<" ";
//					cout<<endl;
//					for(int j=1;j<=3;j++) cout<<a[i][j].id<<" ";
//					cout<<endl;
					G.push_back(a[j][1].val-a[j][2].val);
				}
			}
			p=i;
		}
	}
	sort(G.begin(),G.end());
//	for(int x:G) cout<<x<<endl;
	for(int i=0;i<cnt[p]-n/2;i++) ans-=G[i];
	cout<<ans<<endl;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--) solve();
	return 0;
}
/*
1
4
0 1 0
0 1 0
0 2 0
0 2 0

*/
