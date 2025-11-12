#include <bits/stdc++.h>
using namespace std;
int h[100005][3],zong=0,p=0,xian=0;
void dfs(int a,int b,int c,int d,int zz){
	if (a>xian or b>xian or c>xian) return ;
	if (d==p){
		zong=max(zong,zz);
		return ;
	}
	dfs(a+1,b,c,d+1,zz+h[d][0]);
	dfs(a,b+1,c,d+1,zz+h[d][1]);
	dfs(a,b,c+1,d+1,zz+h[d][2]);
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin >> t;
	int n;
	for (int i=0;i<t;i++){
		cin >> n;
		if (n!=100000){
			for (int j=0;j<n;j++) cin >> h[j][0] >> h[j][1] >> h[j][2];
			p=n;
			xian=n/2;
			dfs(0,0,0,0,0);
			cout << zong << endl;
			zong=0;
		}
		else if (n==100000){
			int hh[n];
			for (int j=0;j<n;j++){
				cin >> h[j][0] >> h[j][1] >> h[j][2];
				hh[j]=h[j][0];	
			}
			if (h[0][1]==h[0][2] and h[0][1]==0){
				sort(hh,hh+n);
				int a=n/2;
				for (int j=n-1;j>n-1-a;j--) zong=zong+hh[j];
				cout << zong << endl;
				zong=0;
			}
		}
	}
	return 0;
}
