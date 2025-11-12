#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pair<int,int>>
#define fi first
#define se second
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(z);x>=(y);x--)
#define eb emplace_back
#define emp emplace
#define pob pop_back
#define tomx(x,y) x=max(x,y)
#define tomn(x,y) x=min(x,y)
#define pof pop_front
#define ull unsigned long long
#define beg begin
#define all(x) beg(x),end(x)
#define allt(x,y,z) beg(x)+y,beg(x)+z
using namespace std;
int _;
#define N 1'000'05
#define mkp make_pair
int a[N][5];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	for(cin>>_;_--;){
		int n;
		cin>>n;
		int ans=0;
		vi v[4];
		rep(i,1,n){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		rep(i,1,n){
			ans+=max({a[i][1],a[i][2],a[i][3]});
			v[max({mkp(a[i][1],1),mkp(a[i][2],2),mkp(a[i][3],3)}).se].eb(i);
		}
		int p=0;
		rep(i,1,3) if((int)v[i].size()>n/2) assert(!p),p=i;
		if(!p){
			cout<<ans<<"\n";
		}else{
			sort(all(v[p]),[&](int x,int y){
				int mx=0,my=0;
				rep(i,1,3) if(p!=i) tomx(mx,a[x][i]);
				rep(i,1,3) if(p!=i) tomx(my,a[y][i]);	
				return a[x][p]-mx>a[y][p]-my;
			});
			for(;(int)v[p].size()>n/2;){
				int t=v[p].back();
				ans-=a[t][p];
				int mx=0;
				rep(i,1,3) if(p!=i) tomx(mx,a[t][i]);
				ans+=mx;
				v[p].pob();
			}
			cout<<ans<<"\n";
		}
		rep(i,1,n){
			a[i][1]=a[i][2]=a[i][3]=0;
		}
	}
}/*
1
4
0 1 0
0 1 0
0 2 0
0 2 0
*/

