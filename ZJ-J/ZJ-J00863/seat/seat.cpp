#include<bits/stdc++.h>
using namespace std;
int a[1001];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>a[1];
	int o=a[1];
	for(int i=2;i<=n*m;i++)cin>>a[i];
	sort(a+1,a+1+n*m);
	int k=0;
	
	for(int i=1;i<=n*m;i++){
		if(a[i]==o)k=i;
	}
	
	k=n*m-k+1;
	cout<<k<<endl;
	int y=(k+n-1)/n;//dijilie
	int x=k%n;
	if(x==0)x=n;
	if(y%2==0){
		x=n+1-x;
	}
	cout<<y<<" "<<x;
	
	cout<<endl;
}