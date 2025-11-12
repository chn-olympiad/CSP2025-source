#include<bits/stdc++.h>
using namespace std;
int t,n,a[100100],b[100100],c[100100],ans=0,A=0,B=0,C=0,flag=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j]>>b[j]>>c[j];
		}
		int maxx;
		for(int j=1;j<=n;j++){
			if(flag==0){
				int maxx=a[j];
				if(maxx<=b[j]) maxx=b[j];
				if(maxx<=c[j]) maxx=c[j];
			}
			if(flag==1){
				int maxx=b[j];
				if(maxx<=c[j]) maxx=c[j];
			}
			if(flag==2){
				int maxx=a[j];
				if(maxx<=c[j]) maxx=c[j];
			}
			if(flag==3){
				int maxx=a[j];
				if(maxx<=b[j]) maxx=b[j];
			}
			if(maxx==a[j]) A++;
			if(maxx==b[j]) B++;
			if(maxx==c[j]) C++;
			if(A==n/2) flag=1;
			if(B==n/2) flag=2;
			if(C==n/2) flag=3;
			ans=ans+maxx;
		}
		cout<<ans<<endl;
	}
	return 0;
}
