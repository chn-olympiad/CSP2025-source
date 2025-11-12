#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int maxn=1e5+10;
int n;
int maxx=-1;
int hom[maxn];
int a[maxn][3];
void dfs(int now,int val){
	if(now==n+1)return;
	for(int i=1;i<=3;i++){
		if(hom[i]<n/2){
			hom[i]++;
			maxx=max(maxx,val+a[now+1][i]);
//			if(i==2)cout << "okok" << endl;
			dfs(now+1,val+a[now+1][i]);
			hom[i]--;
		}
	}
}
void work(){
	cin >>n;
	memset(a,0,sizeof(a));
	memset(hom,0,sizeof(hom));
	maxx=-1;
	for(int i=1;i<=n;i++){
		cin >> a[i][1] >> a[i][2] >> a[i][3];
	}
	dfs(0,0);
	cout << maxx << endl;
	for(int i=1;i<=3;i++)cout << hom[i] << " ";
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >>t;
	while(t--){
		work();
	}
	return 0;
}
