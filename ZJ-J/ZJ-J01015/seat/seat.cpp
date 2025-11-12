#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[121];
	int len=0;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	len=a[1];
	sort(a+1,a+n*m+1,cmp);
	int number=0,r=0,l=n*m+1,mid=0;
	while(r<l-1){
		mid=(l+r)/2;
		if(a[mid]<=len){
			l=mid;
		}else{
			r=mid;
		}
	}
	number=l;
	if(number%n!=0){
		cout<<number/n+1<<" ";
		if((number/n+1)%2==1){
			cout<<number%n;
		}else{
			cout<<n-number%n+1;
		}
	}else{
		cout<<number/n<<" ";
		if((number/n)%2==0){
			cout<<'1';
		}else{
			cout<<n;
		}
	}
	return 0;
}
