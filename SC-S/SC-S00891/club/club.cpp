#include<bits/stdc++.h>
using namespace std;
int a[100001],b[10],sum=0,t,n,ans=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i]>>b[j];
		} 
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			sum+=max(b[j],b[j+1]);
				if(b[j]==sum){
					ans++;
				}
				else if(ans>n/2){
					cout<<4<<endl;
				}		
				else {
					sum+=b[j];
					cout<<sum<<endl;
				}
	}
	}	
return 0;
}