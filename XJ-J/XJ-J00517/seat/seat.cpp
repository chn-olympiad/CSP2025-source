#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100101];
int xb;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int sum=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(sum==a[i]){
			xb=i;
		}
	}
	if(xb%n==0){
		cout<<xb/n<<' ';
	}else{
		cout<<xb/n+1<<' ';
	}
	if(xb%(n*2)<=n){
		if(xb==0){
			cout<<1<<' ';
		}else{
			cout<<xb%(n*2)<<' ';
		}
	}else{
		cout<<n+n-xb+1<<' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

