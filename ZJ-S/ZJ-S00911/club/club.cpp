#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,i,a[100001][3],ans=0;
		cin>>n;
		for(i=0;i<n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
		for(i=0;i<n;i++){
			ans+=max(a[i][0],max(a[i][1],a[i][2]));
		}
		cout<<ans<<endl;
	}
}