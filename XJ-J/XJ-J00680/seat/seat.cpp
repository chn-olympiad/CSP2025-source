#include<bits/stdc++.h>
using namespace std;
const int N=1e2+5;
int n,m,a[N],f,t; 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	f=a[1];
	sort(a+1,a+1+n*m);
	reverse(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++){
		if(a[i]==f){
			t=i;
			break;
		}
	}
	int r=0,c=0;
	if(t%n==0)c=t/n;
	else c=t/n+1;
	int k=t-t/n*n,flag=0;
	if(k==0)r=n,flag=1;
	if(c%2==0&&flag==0){
		r=n-k+1;
	}
	else if(c%2!=0&&flag==0) r=k;
	
	cout<<c<<" "<<r;
	return 0;
} 

