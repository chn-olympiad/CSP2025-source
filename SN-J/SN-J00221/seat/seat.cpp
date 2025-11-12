#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,l,c,a[2010];
	cin>>n>>m;
	l=n*m;
	c=2*n;
	for(int i=0;i<l;i++){
		cin>>a[i];
	}
	int a1=a[0],b;
	sort(a,a+l);
	for(int i=0;i<l;i++){
		if(a[i]==a1){
			b=i;
			break;
		}
	}
	b=l-b;
	int x=b/c,y=b%c;
	if(y<=n) cout<<2*x+1<<" "<<y;
	else{
		y=n+1-y%n;
		cout<<2*x+2<<" "<<y;
	}
	return 0;
}
