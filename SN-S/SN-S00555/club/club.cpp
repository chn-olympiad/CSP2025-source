#include<bits/stdc++.h>
using namespace std;
int n;
int a[10001][3];
int d[10001];
int sum=0,num=0,ans=0;
int main(){
	freopen("club.in","r",stdin);
		freopen("club.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
			cin>>d[i];
		for(int j=1;j<=3;j++){
			cin>>a[i][j];			
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			if(n%2==0){
				if(a[i][j]){
				if(a[i][1]){
			 	sum=a[i][d[j]];
			}else if(a[i][2]){
				num=a[i][d[j+1]];
			}else if(a[i][3]){
				ans=a[i][d[i+2]];
			}
		}	
			}	
			}
			
		}
	cout<<sum<<endl<<num<<endl<<ans;
	return 0;
} 
