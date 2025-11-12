#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int sum=n*m;
	int a[sum+3];
	int b=0;
	for(int i=1;i<=sum;i++){
		cin>>a[i];
		b=a[1];
	}
	sort(a+1,a+sum+1);
	for(int i=1;i<=sum;i++){
		if(a[i]==b){
			if(i==m){
				cout<<m<<" "<<n;
				return 0;
			}
			if(i<m){
				cout<<m-i<<n;
				return 0;
			}
			if(i>m){
				cout<<i-m<<" "<<n;
				return 0;
			}
		}
	}
	return 0;
}