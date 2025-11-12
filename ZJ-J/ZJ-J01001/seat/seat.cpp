#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],s,sum,b,c,d,ans,sum0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	s=n*m;
	cin>>a[1];
 	ans=a[1];
	for(int i=2;i<=s;i++){
		cin>>a[i];
	}
	for(int i=1;i<=s;i++){
		for(int j=1;j<s;j++){
			if(a[j+1]>a[j]){
				swap(a[j+1],a[j]);
			}
		}
	}
	for(int i=1;i<=s;i++){
		if(a[i]==ans){
			sum=i;
		}
	}
	sum0=sum;
	while(sum0>0){
		sum0-=n;
		b++;
	}
	b--;
	if(b%2==0){
		c=sum-b*n;
		cout<<b+1<<" "<<c;
	}
	if(b%2==1){
		c=sum-b*n;
		cout<<b+1<<" "<<n-c+1;
	}
	return 0;
}
