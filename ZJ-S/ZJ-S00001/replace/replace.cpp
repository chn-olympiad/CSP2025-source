#include <bits/stdc++.h>
#define PII pair<int,int>
#define ll long long
using namespace std;
const int N=2e5+5;
const ll p0=1721,p1=1007081219;
int n,q;
string s[N][2];
string t0,t1;

ll pw[N];
ll ha[N][2];//
ll ha0[N];
ll ha1;

ll get(ll ha[], int l, int r){ return ((ha[r]-ha[l-1]*pw[r-l+1])%p1+p1)%p1;}

int ans;
int main(){
//	cout<<5e6*_logb(5e6);
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	pw[0]=1;
	for(int i=1;i<N;i++) pw[i]=pw[i-1]*p0%p1;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		int m=s[i][0].size();
		s[i][0]=" "+s[i][0],s[i][1]=" "+s[i][1];
		for(int j=1;j<=m;j++){
			ha[i][0]=(ha[i][0]*p0+s[i][0][j])%p1;
			ha[i][1]=(ha[i][1]*p0+s[i][1][j])%p1;
		}
//		cout<<ha[i][0]<<" : "<<ha[i][1]<<'\n';
	}
	for(int i=1;i<=q;i++){
		cin>>t0>>t1;
		int m=t0.size();
		t0=" "+t0,t1=" "+t1;
		ha1=0;
		for(int j=1;j<=m;j++){
			ha0[j]=(ha0[j-1]*p0+t0[j])%p1;
			ha1=(ha1*p0+t1[j])%p1;
		}
		ans=0;
		for(int j=1;j<=n;j++){
			int m0=s[j][0].size()-1;
			for(int k=1;k<=m-m0+1;k++){
				ll ha00=(ha0[k-1]*pw[m-(k-1)]%p1+ha[j][1]*pw[m-(k+m0-1)]%p1+get(ha0,k+m0,m))%p1;
				if(get(ha0,k,k+m0-1)==ha[j][0]&&ha00==ha1) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
//4 2
//xabcx xadex
//ab cd
//bc de
//aa bb
//xabcx xadex
//aaaa bbbb

//2 2
//aa ab
//cc cd
//a b
//xyydaazz xyydabzzz
