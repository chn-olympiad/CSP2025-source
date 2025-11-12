#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100005][4];
vector<int>v;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		long long a1=0,a2=0,a3=0,ans=0;
		for(long long i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2] and a[i][1]>=a[i][3]){a1++;a[i][0]=1;}
			else if(a[i][2]>=a[i][1] and a[i][2]>=a[i][3]){a2++;a[i][0]=2;}
			else if(a[i][3]>=a[i][2] and a[i][3]>=a[i][1]){a3++;a[i][0]=3;}
			ans+=max(a[i][1],max(a[i][2],a[i][3]));
		}
		if(max(a1,max(a2,a3))<=n/2){
			cout<<ans<<'\n';
			continue;
		}
		v.clear();
		long long ai;
		if(max(a1,max(a2,a3))==a1)ai=1;
		else if(max(a1,max(a2,a3))==a2)ai=2;
		else if(max(a1,max(a2,a3))==a3)ai=3;
		for(long long i=1;i<=n;i++){
			if(a[i][0]==ai){
				long long m=INT_MAX;
				for(long long j=1;j<=3;j++){
					if(j==ai)continue;
					m=min(m,a[i][ai]-a[i][j]);
				}
				v.push_back(m);
			}
		}
		sort(v.begin(),v.end());
		for(long long i=0;i<max(a1,max(a2,a3))-n/2;i++){
			ans-=v[i];
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
