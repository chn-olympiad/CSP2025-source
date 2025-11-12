#include<bits/stdc++.h>
using namespace std;
int a[102];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int r;
	cin>>r;
	a[1]=r;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			int x=i/n+1;
			int y=i%n;
			if(y==0)y=n,x--;
			if(x%2==0){
				cout<<x<<" "<<n+1-y<<endl;
				return 0;
			}else{
				cout<<x<<" "<<y<<endl;
				return 0;
			}
		}
	}
	return 0;
}