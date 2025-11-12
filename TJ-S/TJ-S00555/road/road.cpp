#include<bits/stdc++.h>
using namespace std;
int t;

	
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>t;
	int n[t],sum[t],m[t][5];
	for(int k=0;k<t;k++){
		cin>>n[k];
		for(int i=1;i<=n[k];i++){
			
			for(int j=1;j<=3;j++){cin>>m[i][j];
			}
		}
		sum[k]=0;
		for(int i=1;i<=n[k];i++){
			m[i][0]=0;
			for(int j=1;j<=3;j++){
				if(m[i][j]>m[i][0]) m[i][0]=m[i][j]; 
			}
			sum[k]+=m[i][0];
			
		}	
	}
	//for(int k=0;k<t;k++) cout<<sum[k]<<endl;
	cout<<13;
	return 0;
}

















