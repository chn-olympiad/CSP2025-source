#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int main(){
    freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,num=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]) num++;
	}
	int k=n*2;
	int p=num/k*2;
	num%=k;
	if(num==0){
		cout<<p<<" "<<1;
	}
	else if(num<=n){
		cout<<p+1<<" "<<num;
	}
	else{
		cout<<p+2<<" "<<k-num+1;
	}
	return 0;
}
