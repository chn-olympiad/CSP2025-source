#include<bits/stdc++.h>
using namespace std;
long long n,m,x,y,num;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	num=n*m;
	for(int i=1;i<=num;i++){
		cin>>a[i];
	}
	long long s=a[1],cnt;
	sort(a+1,a+num+1,greater<int>());
	for(int i=1;i<=num;i++){
		if(a[i]==s){
			cnt=i;
		}
	}
	y=cnt%n;
	if(y==0){
		y=n;
	}
	if(y<n){
		x=cnt/n+1;
	}else{
		x=cnt/n;
	}
	if(x%2==0){
		y=n+1-y;
	}
	cout<<x<<" "<<y;
	return 0;
}