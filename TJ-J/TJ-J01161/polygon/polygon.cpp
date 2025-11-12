#include<bits/stdc++.h>
using namespace std;
int n,a[5001],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int x=2,sum;
	while(n-s>0){
		m=1;
		s=x;
		sum=0;
		while(n-s>0){
			sum+=(n-s)*m;
			m++;
			s++;
		}
		ans+=sum;
		x++;
	}
	cout<<ans;
	return 0;
}
