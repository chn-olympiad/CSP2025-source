#include<bits/stdc++.h>
#define int long long
using namespace std;
int T;
const int N=1e5+10;
int n,a[N][5],f[5],dp[N],b[N];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		int l=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]!=0||a[i][3]!=0){
				l=1;
			}
			dp[i]=0;
			f[i]=0;
		}
		if(!l){
			for(int i=1;i<=n;i++){
				b[i]=a[i][1];
			}
			sort(b+1,b+n+1);
			int sum=0;
			for(int i=1;i<=n/2;i++){
				sum=sum+b[i];
			}
			cout<<sum<<endl;
			continue;
		}
		int sum=0;
		for(int i=1;i<=n;i++){
			sum=sum+max(a[i][1],max(a[i][2],a[i][3]));
		}
		cout<<sum<<endl;
		continue;
	}
	return 0;
}
