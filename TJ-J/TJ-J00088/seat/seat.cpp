#include <bits/stdc++.h>
using namespace std;
int n,m,a[100],s;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)s=a[i];
	}
	sort(a+1,a+(n*m)+1);
	for(int i=(n*m);i>=1;i--){
		if(a[i]==s){
			s=(n*m)-i;
			break;
		}
	}
	int x=s%n,y=s/n;
	if(y%2==0)cout<<y+1<<" "<<x+1;
	else cout<<y+1<<" "<<n-x;
	return 0;
}
