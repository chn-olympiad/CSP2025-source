#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,ans=0;
	int a[106];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			ans=a[i];
		}
	}
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==ans){
			if(i%n==0){
				cout<<i/n<<" ";
			}else{
				cout<<i/n+1<<" ";
			}
			if((i/n+1)%2==0){
				if(i%n==0){
					cout<<n;
					return 0;
				}else{
					cout<<n-i%n+1;
					return 0;
				}
			}else{
				if(i%n==0){
					cout<<1;
					return 0;
				}else{
					cout<<i%n;
					return 0;
				}	
			}
		}
	}
	return 0;
}
