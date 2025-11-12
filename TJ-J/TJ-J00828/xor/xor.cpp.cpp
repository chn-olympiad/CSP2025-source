#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,k,ans,a[1000006],b;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b+=a[i];
	}
	if(k<=0){
		cout<<0;
		return 0;
	} else if(k==1){
		cout<<0;
		return 0;
	}
	return 0;
	
}
