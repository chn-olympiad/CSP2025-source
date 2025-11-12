#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[114],rec;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	rec=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(rec==a[i]){
			cout<<(i-1)/n+1<<" ";
			if(((i-1)/n)%2) cout<<n-(i-1)%n;
			else cout<<(i-1)%n+1;
			return 0;
		}
	}
	return 0;
}