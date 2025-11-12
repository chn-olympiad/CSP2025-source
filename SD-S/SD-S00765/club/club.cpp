#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int n,t,a[N][5],sum=0,maxx=0;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		sum=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				maxx=max(maxx,a[i][j]);
			}
			sum+=maxx;
		}
		cout<<sum<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

