#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
int n,m;
cin>>n>>m;
for(int i=0;i<n*m;i++){
	cin>>a[i];
}int k=a[0];
sort(a,a+n*m,greater<int>());
int d=0;
for(int i=0;i<n*m;i++){
	if(a[i]==k){
		d=i+1;
		break;
	}
}if(d%n==0){
	if((d/n)%2==0){
		cout<<d/n<<" "<<1;
		return 0;
	}else{
		cout<<d/n<<" "<<n;
	}
}else{
	if((d/n)%2==0){
		cout<<d/n+1<<" "<<d%n;
		return 0;
	}else{
		cout<<d/n+1<<" "<<n-d%n+1;
	}
}
	return 0;
} 
