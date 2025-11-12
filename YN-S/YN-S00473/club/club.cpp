#include<bits/stdc++.h>
using namespace std;
long long t,n,p1[100005],p2[100005],p3[100005],ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(long long i=0;i<n;i++)cin>>p1[i]>>p2[i]>>p3[i];
		for(long long i=0;i<n;i++){
			ans+=max(p1[i],max(p2[i],p3[i]));
		}
		cout<<ans;
		for(long long i=0;i<n;i++)p1[i]=p2[i]=p3[i]=0;
		n=0,ans=0;
	}
}