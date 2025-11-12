#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int n,t;
int a[maxn][3];
int dfs(int i,int na,int nb,int nc){
//	cout<<"dfs "<<i<<" "<<na<<" "<<nb<<" "<<nc<<endl;
	if (na==0 && nb==0 && nc==0) return -1;
	if (i == 1){
		return max((na>0?a[i][0]:0),max((nb>0?a[i][1]:0),(nc>0?a[i][2]:0)));
//		if (na>0 && (nb<=0 || a[i][0]>=a[i][1]) && (nc<=0 || a[i][0]>=a[i][2])) return a[i][0];
//		if (nb>0 && (na<=0 || a[i][1]>=a[i][0]) && (nc<=0 || a[i][1]>=a[i][2])) return a[i][1];
//		if (nc>0 && (na<=0 || a[i][2]>=a[i][0]) && (nb<=0 || a[i][2]>=a[i][1])) return a[i][2];
//		return -1;
	}
//	int aa[3] = {};
//	if (na>0)aa[0] = dfs(i-1,na-1,nb,nc)+a[i][0];
//	if (nb>0)aa[1] = dfs(i-1,na,nb-1,nc)+a[i][1];
//	if (nc>0)aa[2] = dfs(i-1,na,nb,nc-1)+a[i][2];
//	cout<<"dfs "<<i<<" on "<<aa[0]<<" "<<aa[1]<<" "<<aa[2]<<endl;
	return max((na>0?dfs(i-1,na-1,nb,nc)+a[i][0]:0),max((nb>0?dfs(i-1,na,nb-1,nc)+a[i][1]:0),(nc>0?dfs(i-1,na,nb,nc-1)+a[i][2]:0)));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while (t--){
		cin>>n;
		for (int i = 1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
		cout<<dfs(n,n/2,n/2,n/2)<<endl;
	}
	return 0;
}