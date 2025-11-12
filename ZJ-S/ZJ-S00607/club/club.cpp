#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define endl '\n'
#define int long long
using namespace std;
const int N=1e5+5;
struct node{
    int x,y,z;
}a[N];
bool cmp(node x,node y){
	if(x.x!=y.x)return x.x>y.x;
	else if(x.y!=y.y)return x.y>y.y;
	else return x.z>y.z;
}
int n;
int ans=0;
int m;
void dfs(int x,int sum1,int sum2,int sum3,int cnt){
	if(sum1>m)return;
	if(sum2>m)return;
	if(sum3>m)return;
	if(x==n+1){
		if(cnt>ans){
			ans=cnt;
		}
	}
	dfs(x+1,sum1+1,sum2,sum3,cnt+a[x].x);
	dfs(x+1,sum1,sum2+1,sum3,cnt+a[x].y);
	dfs(x+1,sum1,sum2,sum3+1,cnt+a[x].z);
}
void solve(){
    cin>>n;
    ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y>>a[i].z;
    }
//    sort(a+1,a+1+n,cmp);
    m=n/2;
    dfs(1,0,0,0,0);
    cout<<ans<<endl;
}
signed main(void){
     freopen("club.in","r",stdin);
     freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
/*
m*m 3
*/