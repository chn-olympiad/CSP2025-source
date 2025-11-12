#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int num=a[1];
	sort(a+1,a+n*m+1);
	int sum;
	for(int i=1;i<=n*m;i++){
		if(a[i]==num){
			sum=n*m-i;
			break;
		}
	}
	if((sum/n)%2!=0&&sum/n!=0){
		cout<<sum/n+1<<" "<<n-sum%n;
	}else{
		cout<<sum/n+1<<" "<<sum%n+1;
	}
	
	return 0;
} 
