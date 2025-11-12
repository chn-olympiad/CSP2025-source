#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	int s=a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==s){
			int x=0;
			if(i<=n){
				x=1;
			}
			else{
				x=i/n+1;
			}
			int y=i%n;
			if(y==0){
				y=n;
			}
			if(x%2==1){
				cout<<x<<" "<<y;
				return 0;
			}
			else{
				cout<<x<<" "<<m-y+1;
				return 0;
			}
		}
	}
	return 0;
}
