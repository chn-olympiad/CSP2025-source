#include <bits/stdc++.h>
using namespace std;
int z;
int p[100][4];
int a[4]={0};
int dfs(int as,int rs) {
	rs++;
	if(rs>z) {
		return as;
	}
	int da;
	int mx=-10000;
	for(int i=1; i<=3; i++) {
		if(a[i]+1<=z/2) {
			a[i]++;

			int r=as+p[rs-1][i];
		//		 cout<<as<<"->";
			da=dfs(r,rs);
		//		cout<<"\n";
			mx=max(mx,da);
			a[i]--;
		}
	}

	return mx;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int x;
	cin>>x;
	for(int i=0; i<x; i++) {

		cin>>z;
		a[1]=0;
		a[2]=0;
		a[3]=0;
		for(int j=0; j<z; j++) {
			cin>>p[j][1]>>p[j][2]>>p[j][3];

		}
		int ans=dfs(0,0);
		cout<<ans;
	}
}
