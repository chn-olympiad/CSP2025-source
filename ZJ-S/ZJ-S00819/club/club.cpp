#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define eb emplace_back
const int N=1e5+10;
int T,n,sum;
pii a[N][4];
int t[4];
int cnt,del[N];
signed main(){
	freopen("club.in","r",stdin);freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1,x,y,z;i<=n;i++){
			cin>>x>>y>>z;
			a[i][1]={x,1},a[i][2]={y,2},a[i][3]={z,3};
		}
		for(int i=1;i<=n;i++){
			sort(a[i]+1,a[i]+3+1,greater<pii>());
			sum+=a[i][1].fi,t[a[i][1].se]++;
		}
		for(int i=1;i<=n;i++){
			if(t[a[i][1].se]>n/2) del[++cnt]=a[i][1].fi-a[i][2].fi;
		}
		sort(del+1,del+cnt+1);
		int now=max({t[1],t[2],t[3]});
		for(int i=1;i<=cnt&&now>n/2;i++,now--) sum-=del[i];
		cout <<sum<<"\n";
		sum=t[1]=t[2]=t[3]=cnt=0;
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
