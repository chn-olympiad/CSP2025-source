#include<bits/stdc++.h>
using namespace std;

int a[1010];

bool cmp(int x,int y){
	return x>y;
}

signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int x=a[1];
	sort(a+1,a+n*m+1,cmp);
	int pos;
	for(int i=1;i<=n*m;i++) {
		if(a[i]==x) pos=i;
	}
	pos--;
	int c=pos/n,r;
	if(c%2==0){
		r=pos%n;
	}
	else{
		r=n-1-pos%n;
	}
	cout<<c+1<<' '<<r+1;
	return 0;
}
