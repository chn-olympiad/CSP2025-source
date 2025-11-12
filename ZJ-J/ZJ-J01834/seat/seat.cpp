#include<bits/stdc++.h>
using namespace std;
const int mx=13;
int a[mx*mx];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m*n;i++)cin>>a[i];
	int a1=a[1];
	sort(a+1,a+1+n*m);
	int k;
	for(int i=1;i<=n*m;i++){
		if(a[i]==a1){
			k=n*m-i+1;
			break;
		}
	}
	int m1=k/n+1,n1;
	n1=k%n;
	if(n1==0){
		n1=n;
		m1--;
	}
	if(m1%2==0)n1=n-n1+1;
	cout<<m1<<" "<<n1;
	return 0;
}