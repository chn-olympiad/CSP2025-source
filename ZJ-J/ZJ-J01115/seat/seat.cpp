#include<bits/stdc++.h>
using namespace std;
long long a[1005];
bool cmp(int a,int b){
	if(a>b){
		return true;
	}else{
		return false;
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,b=0,c=0,x=0,y=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	b=a[1];
	sort(a+1,a+(n*m)+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==b){
			c=i;
			break;
		}
	}
	y=c%n;
	if(y==0){
		x=c/n;
		if(x%2==1){
			cout<<x<<" "<<n;
		}else{
			cout<<x<<" "<<n-y+1;
		}
	}else{
		x=c/n+1;
		if(x%2==1){
			cout<<x<<" "<<y;
		}else{
			cout<<x<<" "<<n-y+1;
		}
	}
	return 0;
}
