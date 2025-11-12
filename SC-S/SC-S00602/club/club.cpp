#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
#define m(a) memset(a,0,sizeof(a))
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int N=1e5+10;
int n,m,k,T;
int ans,sum[5];
pair<int,int> a[5];
struct node{
	int x1,ch,a,b;
}q[N];
void init(){
	m(sum);ans=0;m(sum);
}
bool cmp(node a,node b){
	return a.ch>b.ch;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;int mx=n/2;
        init();
        rep(i,1,n){
        	int x,y,z;cin>>x>>y>>z;
        	a[1]={x,1};a[2]={y,2};a[3]={z,3};
        	sort(a+1,a+4);
            q[i]={a[3].fi,a[3].fi-a[2].fi,a[3].se,a[2].se};
		}sort(q+1,q+n+1,cmp);
		rep(i,1,n){
			node t=q[i];
			if(sum[t.a]>=mx){
				ans+=t.x1-t.ch;sum[t.b]++; 
			}else{
				ans+=t.x1;sum[t.a]++; 
			}
		}cout<<ans<<'\n';
    }
	return 0;
}