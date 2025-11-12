#include<bits/stdc++.h>
using namespace std;
int T,n,a[100005],b[100005],c[100005],maxx,dp[100005];
int aa,bb,cc,ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	int maxx=-1e9;
	while(T--){
		cin>>n;
		for(int i=0;i<n;i++){
			vector<int> v;
			vector<int> v1;
			vector<int> v2;
			cin>>a[i]>>b[i]>>c[i];
			v.push_back(a[i]);
			v1.push_back(b[i]);
			v2.push_back(c[i]);
			maxx=max(a[i],max(b[i],c[i]));
			if(a[i]==maxx){
				aa++;
			}
			if(b[i]==maxx){
				bb++;
			}
			if(c[i]==maxx){
				cc++;
			}
			if(aa<=n/2&&bb<=n/2&&cc<=n/2){
				ans+=maxx;
			}
			else{
				for(int k=0;k<n/2;k++){
					ans+=max(v[i],max(v1[i],v2[i]));
				}
			}
		}
		cout<<ans<<endl;
		ans=0;
		maxx=0;
	}
	/*/
	3
	4
	4 2 1
	3 2 4
	5 3 4
	3 5 1
	4
	0 1 0
	0 1 0
	0 2 0
	0 2 0
	2
	10 9 8
	4 0 0
	/*/
	return 0;
}
