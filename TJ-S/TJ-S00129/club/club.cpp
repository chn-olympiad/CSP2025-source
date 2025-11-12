#include<bits/stdc++.h>
using namespace std;
int arr[100005][100005]={};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int a=1;a<=t;a++){
		int n;
		cin>>n;
		int sum=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>arr[i][j];
			}
		}
		int sum=0;
		for(int i=1;i<=n;i++){
			sum+=arr[i][1];
		}
		cout<<sum<<endl;
	}
	return 0;
} 
