#include<bits/stdc++.h>
using namespace std;
const int N=1010;
bool cmp(int a,int b){
	return a>=b;
}
int a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int r=a[1];
	sort(a+1,a+n*m+1,cmp);
	int id;
	for(int i=1;i<=n*m;i++){
		//cout<<a[i]<<" ";
		if(a[i]==r){
			id=i;
		}
	}
	int x;
	if(id%n==0) x=id/n;
	else x=id/n+1;
	int y;
	if(x%2==0){
		//y=n-id%n
		if(id%n==0){
			y=1;
		}else y=n-id%n+1;
	}else if(x%2==1){
		if(id%n==0){
			y=n;
		}else y=id%n;
	}
	cout<<x<<" "<<y;
	return 0;
}
