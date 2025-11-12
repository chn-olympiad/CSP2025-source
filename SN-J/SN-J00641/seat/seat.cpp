#include<bits/stdc++.h>
using namespace std;
int a[1001];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,sum,num=0,b=1;
	cin>>n>>m;
	sum=n*m;
	for(int i=1;i<=sum;i++){
		cin>>a[i];
	}
	for(int i=1;i<=sum;i++){
		if(a[0]<a[i]){
			num=num+1;
		}
	}
	if(num==0){
		cout<<"1"<<" "<<"1";
		return 0;
	}
	while(num>=n){
		if(num>=n){
			num-=n;
			b++;
		}
	}
	cout<<b<<" "<<num;
	return 0;
}

