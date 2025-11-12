#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,j,i;
	int sum=0;
	char a[i];
	cin>>t;
	for(int i=0;i<=t;i++){
		cin>>n;
		for(int j=0;j<n;j++){
			cin>>a[i];
			sum+=max(sum,a[i]+a[(i+1)]);
			cout<<sum;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
	
	
	
}

