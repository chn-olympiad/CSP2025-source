#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1009];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int k=a[1];
	
	sort(a+1,a+1+m*n,greater<int>());
	
	int p=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			p=i;
			break;
		}
	}
	int x=ceil(p*1.0/(n*1.0));//lie
	int y=(p-1)%n;//hang
	if(x%2){
		cout<<x<<" "<<y+1;
	}
	else{
		cout<<x<<" "<<n-y;
	}
	return 0;
}
