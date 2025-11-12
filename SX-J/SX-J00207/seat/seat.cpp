#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
int a[200];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int k=a[1];
	sort(a+1,a+1+(n*m),cmp);
	int id;
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			id=i;
			break;
		}
	}
	int c,r;
	if(id%n==0){
		c=id/n;
		if(c%2==0) r=1;
		else r=n;
	}
	else{
		c=id/n+1;
		if(c%2==0) r=n-(id%n)+1;
		else r=id%n;
	}
	cout<<c<<" "<<r;
	return 0;
}


