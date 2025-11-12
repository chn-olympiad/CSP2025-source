//何乐怡 SN-J00035 西安滨河学校
#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int ans=a[1];
	sort(a,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		int j=n*m-i+1;
		if(a[i]==ans){
			if(j%n==0){
				if(j/n%2==0){
					cout<<j/n<<" "<<endl;
					return 0;
				}
				else{
					cout<<j/n<<" "<<n;
					return 0;
				}
				return 0;
			}
			else{
				if((j/n+1)%2==0){
					cout<<j/n+1<<" "<<n-(j%n)+1;
					return 0;
				}
				else{
					cout<<j/n+1<<" "<<j%n;
					return 0;
				}
			}
		}
		else continue;
	}
	return 0;
} 
