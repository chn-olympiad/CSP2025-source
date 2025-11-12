#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int x,k,c,r;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			x=a[i];
		}
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			k=i;
		}
	}
	if(k%n==0){
		c=k/n;
	}else{
		c=k/n+1;
	}
	if(c==1){
		r=k;
		cout<<c<<" "<<r;
		return 0;
	}
	if(c%2==0){
		if(k%n==0){
			r=1;
		}
		else{
			r=n-(k%n)+1;
		}
	}else{
		if(k%n==0){
			r=n;
		}else{
			r=k%n;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
