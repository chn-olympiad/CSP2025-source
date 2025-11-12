#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("club.in","r",stdin);	
freopen("club.out","w",stdout); 	
int t,a[100001][3];
cin.tie(0);
cin>>t;
while(t--){
long long n,mx,ans=0;
cin>>n;
mx=n/2;	
int s1[n],s2[n],s3[n];
for(int i=1;i<=n;i++){
	
	cin>>a[i][1];
	cin>>a[i][2];
	cin>>a[i][3];
	

}	
for(int i=1;i<=n;i++){
	if(a[i][1]>a[i][2] && a[i][1]>a[i][3]){
		ans+=a[i][1];
	}
	if(a[i][2]>a[i][1] && a[i][2]>a[i][3]){
		ans+=a[i][2];
	}	
	if(a[i][3]>a[i][2] && a[i][3]>a[i][1]){
		ans+=a[i][3];
	}	
	

}
cout<<ans<<'\n';
ans=0;	
}
return 0;
}
