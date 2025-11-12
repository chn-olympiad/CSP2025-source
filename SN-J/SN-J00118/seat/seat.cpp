#include<bits/stdc++.h>
using namespace std;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s,x;
	int sn,sm;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+(n*m)+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==s) x=i; 
	}
	x=n*m-x+1;
	int t=x;
	sn=x/n+1;
	if(x%n==0) sn--;
	if(x%n==0) t--;
	if((t/n)%2==0){
		sm=x%n;
		if(sm==0) sm=n;
	}else{
		sm=n-(x/n)+1;
	}
	cout<<sn<<" "<<sm;
}
