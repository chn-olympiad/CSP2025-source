#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[1110],ans=0,sum=0,flag=0;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	if(n==1&&m==1){
		cout<<"1 1";
	}else{
		ans=a[1];
		sort(a,a+n*m);
		for(int i=0;i<n*m;i++){
			if(a[i]==ans){
				sum=i;
				break;
			}
		}
		for(int i=n;i>=0;i--){
			for(int j=m;j>=0;j--){
				flag++;
				if(flag==sum){
					cout<<i<<" "<<j;
				}
			}
	}
	}
	return 0;
}
