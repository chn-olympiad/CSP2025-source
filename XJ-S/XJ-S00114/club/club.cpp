#include<bits/stdc++.h>

using namespace std;


int main(){

	freopen("clun.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;//t组数据 
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		//n为人
		//每个人对每个组的喜爱程度 
		int a[1000][5];
		int ans=0;
		for(int j=1;j<=n;j++){
			//每个组的数据 
			
			for(int k=1;k<=3;k++){
				cin>>a[j][k];
				int cemax=max(a[j][1],a[j][2]);
				cemax=max(cemax,a[j][3]);
				a[j][0]=cemax;
				int id;
				if(cemax==a[j][1]) id=1;
				if(cemax==a[j][2]) id=2;
				if(cemax==a[j][3]) id=3;
				a[j][4]=id;
				
				
				
			}
			ans+=a[j][0];	

		}
		cout<<ans<<endl;
		/*
		for(int j=1;j<=n;j++){
			
			cout<<a[j][0];
				
			
			cout<<endl;
			

		}*/
		
		
		
		
	}
	
	return 0;
} 
