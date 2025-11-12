#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int sum=0;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]) sum++;
	}
	cout<<sum/n+1<<" ";
	if((sum/n+1)%2==1){
		cout<<sum%n+1;
	}
	else cout<<n-sum%n;
	return 0;
}
