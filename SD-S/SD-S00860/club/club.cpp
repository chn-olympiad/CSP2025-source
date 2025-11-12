#include<bits/stdc++.h>
using namespace std;
int n,t; 
const int maxn = 1e5+10;
int a[maxn][3];
int f[maxn];
long long ans;
 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin>>t;
	for(int i = 1;i<=t;i++){
		ans=0;
		int s1,s2,s3;
		cin>>n;
		for(int j = 1;j<=n;j++){
			cin>>a[j][1]>>a[j][2]>>a[j][3];
			if(a[j][1]) s1++;
			if(a[j][2]) s2++;
			if(a[j][3]) s3++;
			ans+=max(max(a[j][1],a[j][2]),a[j][3]);
		}
		cout<<ans<<"\n";
		
	}
	return 0;
}

