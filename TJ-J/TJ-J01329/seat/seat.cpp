#include<iostream>
#include<algorithm>
using namespace std;
int a[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r,cnt=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	cnt=a[1];
	for(int i=2;i<=n*m;i++){
		if(a[i]>cnt) r++;
	}
//	cout<<r<<"&&";
	if(r<n){
		cout<<1<<" "<<r+1;
	}
	else{
		int c=r/n;
		if(c%2==0){
			cout<<c+1<<" "<<r%n+1;
		}
		else{
			cout<<c+1<<" "<<n-r%n;
		}
	}
	return 0;
} 
