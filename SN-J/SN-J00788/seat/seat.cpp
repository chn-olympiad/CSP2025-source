#include<bits/stdc++.h>
using namespace std;
int n,m,k,cnt=1,arr[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>arr[i];
		if(i==1) k=arr[1];
		else if(arr[i]>k) cnt++;
	}
	k=cnt%(n*2);
	if(k==0){
		cout<<cnt/n<<" "<<1;
		return 0;
	}
	if(cnt%n==0){
		cout<<cnt/n<<" "<<n;
		return 0;
	}
	cout<<cnt/n+1<<" ";
	if(k<n) cout<<k;
	else cout<<2*n-k+1;
	return 0;
}
