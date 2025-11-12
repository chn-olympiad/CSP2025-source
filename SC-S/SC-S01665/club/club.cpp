// Anohinosquid @ Hypixel Skyblock
// 2025-2026 Testify the overcoming. 
#include<bits/stdc++.h>
#define F(i,x,y) for (int i=(x);i<=(y);i++)
using namespace std;

const int N=1e5+5;
int n,a[N][4];
vector<int> d[4]; 
void solve () {
	cin>>n;
	F(i,1,n) {
		F(j,1,3) cin>>a[i][j];
	}
	int ans=0;
	F(i,1,n) {
		int k=1;
		F(j,2,3) {
			if (a[i][j]>a[i][k]) k=j;
		}
		ans+=a[i][k];
		int cur=a[i][k];
		if (k==1) cur-=max(a[i][2],a[i][3]);
		else if (k==2) cur-=max(a[i][1],a[i][3]);
		else cur-=max(a[i][1],a[i][2]);
		d[k].push_back (cur);
	}
	F(i,1,3) sort (d[i].begin (),d[i].end ());
	F(i,1,3) {
		if (d[i].size()>n/2) {
			F(j,0,d[i].size()-n/2-1) ans-=d[i][j];
		}
	}
	cout<<ans<<"\n";
} 
void cleanup () {
	F(i,1,3) d[i].clear ();
}
int main () {
	freopen ("club.in","r",stdin);
	freopen ("club.out","w",stdout);
	ios::sync_with_stdio (0); cin.tie (0);
	int testcases;
	cin>>testcases;
	while (testcases--) { solve (); cleanup(); }
	return 0;
}