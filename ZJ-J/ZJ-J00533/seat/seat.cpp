#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,a[101],t;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	t=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==t){
			cout<<(i-1)/n+1<<" "<<((((i-1)/n+1)%2)?(i-1)%n+1:n-(i-1)%n)<<endl;
			return 0;
		}
	}
	return 0;
}
//11.1 8:52
//code by K.S.
