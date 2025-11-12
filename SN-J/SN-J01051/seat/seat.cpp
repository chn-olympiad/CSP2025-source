#include<bits/stdc++.h>
using namespace std;
int a[110]={0},b[110][110],num;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int ans=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==ans){
			num=n*m-i+1;
		}
	} 
	cout<<1<<" "<<num;
	return 0;
} 
