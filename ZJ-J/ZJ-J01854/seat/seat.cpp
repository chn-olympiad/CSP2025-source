#include<bits/stdc++.h>
using namespace std;
bool cmp(int k,int l){
	return k>l;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[108],n,m,b,c,x=1,y=0;
	cin>>m>>n;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	b=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;;i++){
		if(b==a[i]){
			c=i;
			break;
		}
	}
	while(c>n){
		x++,c-=n;
	}
	if(x%2==1)
		cout<<x<<' '<<c;
	else
		cout<<x<<' '<<n-c+1;
	return 0;
}
