#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1005];
int p,t;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	p=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==p){
			t=i;
			break;
		}
	}
	int l=(t-1)/n+1;
	int y=t%n;
	if(y==0)y=n;
	if(l%2==0){
		cout<<l<<" "<<n-y+1;
	}
	if(l%2==1){
		cout<<l<<" "<<y;
	}
	return 0;
} 
