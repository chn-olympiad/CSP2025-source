#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n;
int main(){
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int a[N][5],sum=0,maxn=-1;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				maxn=max(maxn,a[i][j]);
			}
			sum+=maxn;
		}
		cout<<sum<<"\n";
	}
	return 0;
}