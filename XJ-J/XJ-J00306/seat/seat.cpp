#include<bits/stdc++.h>
int a[10005];
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,b=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
		for(int i=1;i<=n*m;i++){
		if(a[0]<a[i]){
			b+=1;
		}
	}
	if (b%n!=0){
		if(b/2==n){
			cout<<b/n+1<<" "<<b%2;
		}
		else{
			cout<<b/n+1<<" "<<n+1-b%2;
		}
	}
	else{
		cout<<b/n<<" "<<1;
	}
	return 0; 

}
