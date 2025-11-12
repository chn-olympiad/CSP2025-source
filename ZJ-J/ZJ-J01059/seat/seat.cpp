#include<bits/stdc++.h>
using namespace std;
string s;
int n,m,cnt,ans,a[10005],t,x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	t=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==t){
			t=n*m-i+1;
			break;
		}
	}
	x=t/n+1;
	y=t%n; 
	if(x%2==0)cout<<n-y+1<<" ";
	else cout<<y<<" ";
	cout<<x;
	return 0;
}
