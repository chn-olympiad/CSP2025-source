#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
int a[110];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int w=a[1];
	sort(a+1,a+n*m+1,cmp);
	int id=-1;
	for(int i=1;i<=n*m;i++) {
		if(a[i]==w){id=i;break;}
	}
	int c=(id+n-1)/n,r=-1;
	if(id%n==0){
		if(c%2==0) r=1;
		else r=n;
	}
	else if(c%2==1) r=id%n;
	else r=n-(id%n)+1;
	cout<<c<<' '<<r;
	return 0;
}
