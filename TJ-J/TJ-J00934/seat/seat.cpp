#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],s,sum;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(s==a[i]){
			sum++;
			if(sum>n){
				cout<<sum/n+1<<" ";
				if((sum/n+1)%2==0){
					cout<<n-sum%n+1;
				}else{
					cout<<sum%n;
				}
			}else{
				cout<<1<<" "<<n;
			}
			return 0;
		}else{
			sum++;
		}
	}
	return 0;
}
