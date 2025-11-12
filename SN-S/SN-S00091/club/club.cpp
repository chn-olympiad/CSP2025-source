#include<bits/stdc++.h>
using namespace std;
long long t,n,a1,a2,a3,maxx;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		unsigned long long ans=0;
		for(int i=0;i<n;i++){
			cin>>a1>>a2>>a3;
			ans+=max(max(a1,a2),a3);
		}
		cout<<ans<<endl;
	}
	return 0;
}
