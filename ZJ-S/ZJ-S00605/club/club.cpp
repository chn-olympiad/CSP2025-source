#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club5.in","r",stdin);
	freopen("club10.out","w",stdout);
	int t;
	int n;
	int sum;
	cin>>t>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			int arr[i][j];
			cin>>arr[i][j];
			sum=sum+arr[i][j];
		}
	}
	cout<<sum;
	return 0;
}
