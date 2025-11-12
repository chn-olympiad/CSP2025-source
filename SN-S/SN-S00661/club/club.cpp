#include<bits/stdc++.h>
using namespace std;
int t,n,ep;
long long sum;
int a[20005][20005];
int one,two,three;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	ep=n/2;
	while(t--){
		cin>>n;
		one=0;two=0;three=0,sum=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		} 
		
		int i=1,j=1;
		if(a[i][j]>a[i][j+1]>a[i][j+2] && one<=ep){
			sum+=a[i][j];
			one++;
		}else{
			if(a[i][j+2]>a[i][j+1] && two<=ep){
				sum+=a[i][j+2];
				two++;
			}else{
				sum+=a[i][j+2];
				three++;
			}
		}
		if(a[i][j+1]>a[i][j+2]>a[i][j] && two<=ep){
			sum+=a[i][j+1];
			two++;
		}else{
			if(a[i][j]>a[i][j+2] && one<=ep){
				sum+=a[i][j]; 
				one++;
			}else{
				sum+=a[i][j+1];
				two++;
			}
		}
		if(a[i][j+2]>a[i][j+1]>a[i][j] && three<=ep){
			sum+=a[i][j+2];
			three++;
		}else{
			if(a[i][j]>a[i][j+1] && one<=ep){
				sum+=a[i][j]; 
				one++;
			}else{
				sum+=a[i][j+1];
				two++;
			}
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
