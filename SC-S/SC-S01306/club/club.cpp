#include<bits/stdc++.h>
using namespace std;

int max3(int a,int b,int c){
	int m;
	m=max(a,b);
	m=max(m,c);
	return m;
}
int min3(int a,int b,int c){
	int m;
	m=min(a,b);
	m=min(m,c);
	return m;
}






int plan(){
	int n;
	int a[100001][3];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i][0]; 
		cin>>a[i][1];
		cin>>a[i][2];
	}
	
	bool goodi[100001][3];
	int sum=0;
	int good[3];
	good[0]=0;
	good[1]=0;
	good[2]=0;
	for(int i=1;i<=n;i++){    
		int m=max3(a[i][0],a[i][1],a[i][2]);
		sum+=m;
		for(int j=0;j<3;j++){    
			
			if(m==a[i][j]){
				
				good[j]++;
				
				goodi[i][j]=1;
			}
		}
	}
	
	bool flag=1;
	int broke;
	for(int j=0;j<3;j++){
		if(good[j]>n/2){
			broke=j;
			flag=0;
		}
	}
	if(flag){
		return sum;
	}


	
	
	return 0;
}





int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,ans[6];
	cin>>t;
	for(int i=1;i<=t;i++){
		ans[i]=plan();
	}
	for(int i=1;i<=t;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}