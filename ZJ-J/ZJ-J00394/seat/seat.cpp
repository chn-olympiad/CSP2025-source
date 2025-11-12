#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int num;
int cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			num=a[i];
		}
	}
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--){
		if(a[i]==num){
			cnt=n*m-i+1;
		}
	}
	int x=cnt%n,y=cnt/n;
	if(x==0){
		cout<<y<<' ';
		if(y%2==0){
			cout<<1;
		}else{
			cout<<n;
		}
	}else{
		cout<<y+1<<' ';
		if((y+1)%2==0){
			cout<<n-x+1;
		}else{
			cout<<x;
		}
	}
	return 0;
}