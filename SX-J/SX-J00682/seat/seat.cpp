#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int x,y;cin>>x>>y;
	int a[x*y+5];int s=0;int n=x;
	for(int i=1;i<=x*y;i++){
		cin>>a[i];
	}
	s=a[1];int js=0;
	sort(a+1,a+1+x*y);
	for(int i=1;i<=x*y;i++){
		if(a[i]==s){
			js=i;break;
		}
	}
	int t=0;
	if(js%n==0){
		cout<<js/n<<" ";t=js/n;
	}
	else{
		cout<<js/n+1<<" ";t=js/n+1;
	}
	if(t%2==1){
		if(js%n==0) cout<<n;
		else cout<<js%n;
	}
	if(t%2==0){
		if(js%n==0) cout<<1;
		else cout<<n-(js%n)+1;
	}
	return 0;
}