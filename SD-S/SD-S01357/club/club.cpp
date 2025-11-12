//Ren5Jie4Di4Ling5%
#include<bits/stdc++.h>
#define int long long
#define rep(x,y,z) for(int x=y;x<=z;++x)
#define per(x,z,y) for(int x=z;x>=y;--x)
#define qwq cout<<'\n'
#define exq exit(0)
using namespace std;
void IOS(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
}
void Document(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
}
bool sta__;
const int N=1e5+55;
int n;
int bo[N];
int bop[N];
int a[N][5];
int t[5];
int sum;
int c[N];
int tot;
void solve(int x){
	tot=0;
	rep(i,1,n){
		if(bo[i]==x){
			c[++tot]=a[i][bo[i]]-a[i][bop[i]];
		}
	}
	sort(c+1,c+1+tot);
	rep(i,1,t[x]-n/2) sum-=c[i];
}
bool end__;
main(){
	IOS();
	Document();
//	cerr<<(&sta__-&end__)/1000/1000;
	int Ct;
	cin>>Ct;
	rep(cas,1,Ct){
		cin>>n;
		rep(i,1,n)
		rep(o,1,3) cin>>a[i][o];
		sum=0;
		rep(i,1,n){
			bo[i]=1;
			rep(o,2,3) if(a[i][o]>a[i][bo[i]]) bo[i]=o;
			t[bo[i]]++;
			sum+=a[i][bo[i]];
			bop[i]=1;
			if(bo[i]==1) bop[i]=2;
			rep(o,1,3){
				if(o==bo[i]) continue;
				if(a[i][bop[i]]<a[i][o]) bop[i]=o;
			}
		}
		rep(i,1,3) t[i]=0;
		rep(i,1,n){
			t[bo[i]]++;
		}
		rep(i,1,3) if(t[i]>n/2) solve(i);
		cout<<sum;
		qwq;
	}
	return 0;
}
