#include<bits/stdc++.h>
using namespace std;
int a[105];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int a1=a[1],c;
	sort(a+1,a+(n*m)+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a1==a[i]){
			c=i;
			break;
		}
	}
	int l=0;
	if(c%n==0){
		int q=c/n; 
		if(q%2==0){
			cout<<q<<" "<<1;
			return 0;
		}else{
			cout<<q<<" "<<n;
			return 0;
		}
	}else{
		l=c/n+1;
		cout<<l<<" ";
	}
	int h;
	if(l%2==0){
		c=c%n-1;
		h=n-c;
		cout<<h;
	}else{
		c=c%n;
		cout<<c;
	}
	return 0;
} 
