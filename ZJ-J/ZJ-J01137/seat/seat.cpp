#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int ans=0;
	int sum=n*m;
	for(int i=1;i<=sum;i++){
		cin>>a[i];
		if(i==1){
			ans=a[i];
		}
	}
	sort(a+1,a+1+sum,cmp);
	int x=1,y=1;
	for(int i=1;i<=sum;i++){
		//cout<<y<<' '<<x<<"\n";
		if(a[i]==ans){
			cout<<y<<" "<<x;
			return 0;
		}
		if(y%2==1){
			x++;
		}
		else{
			x--;
		}
		if(x<=0){
			x=1;
			y++;
		}
		if(x>n){
			x=n;
			y++;
		}
	}
	return 0;
}