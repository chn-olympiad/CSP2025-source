#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
int a[105];
bool cmp(int a,int b){
	return a>b;
}
int r,x=1,y=1,dx=1;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			cout<<y<<' '<<x;
			return 0;
		}
		x+=dx;
		if(x<1) x=1,y++,dx=1;
		if(x>n) x=n,y++,dx=-1;
	}
	return 0;
}
