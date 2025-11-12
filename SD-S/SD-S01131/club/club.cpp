//
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rop(i,a,b) for(int i=a;i<b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define por(i,a,b) for(int i=a;i>b;i--)
#define endl '\n'
#define pii pair<int,int>
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef double lf;
typedef long double ld;
using namespace std;
int t,n,a[100005][5],tot[5],ans;
struct node{
	int a,b,c;
}b[5][100005];
bool cmp1(node x,node y){
	return min(x.a-x.b,x.a-x.c)<min(y.a-y.b,y.a-y.c);
}
bool cmp2(node x,node y){
	return min(x.b-x.a,x.b-x.c)<min(y.b-y.a,y.b-y.c);
}
bool cmp3(node x,node y){
	return min(x.c-x.a,x.c-x.b)<min(y.c-y.a,y.c-y.b);
}
void solve(){
	cin>>n;
	ans=tot[1]=tot[2]=tot[3]=0;
	rep(i,1,n){
		rep(j,1,3)
			cin>>a[i][j];
		rep(j,1,3)
			if(a[i][j]==max(max(a[i][1],a[i][2]),a[i][3])){
				b[j][++tot[j]]={a[i][1],a[i][2],a[i][3]};
				ans+=a[i][j];
				break;
			}
	}
	rep(i,1,3)
		if((tot[i]<<1)>n){
			if(i==1){
				sort(b[i]+1,b[i]+tot[i]+1,cmp1);
				rep(j,1,tot[i]-(n>>1))
					ans-=min(b[i][j].a-b[i][j].b,b[i][j].a-b[i][j].c);
			}
			if(i==2){
				sort(b[i]+1,b[i]+tot[i]+1,cmp2);
				rep(j,1,tot[i]-(n>>1))
					ans-=min(b[i][j].b-b[i][j].a,b[i][j].b-b[i][j].c);
			}
			if(i==3){
				sort(b[i]+1,b[i]+tot[i]+1,cmp3);
				rep(j,1,tot[i]-(n>>1))
					ans-=min(b[i][j].c-b[i][j].a,b[i][j].c-b[i][j].b);
			}
			break;
		}
	cout<<ans<<endl;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--)
		solve();
	return 0;
}
/*
100
*/

