#include<iostream>
#include<cmath>
using namespace std;
const int N=15;
int n,m,cnt; 
int a[N*N];
int main(){
	freopen("seat.in","r",stdout);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	    cin>>a[i];
	for(int i=1;i<=n*m;i++){
		if(a[i]>=a[1]) cnt++;
	}
	cout<<ceil(cnt*1.0/n)<<' ';
	if(int(ceil(cnt*1.0/n))%2==0){
		if(cnt%n!=0)
			cout<<n-(cnt%n)+1;
		if(cnt%n==0)
		    cout<<1;
	}
	else{
		if(cnt%n!=0)  cout<<cnt%n;
		else cout<<n;
	}
	return 0;
}
