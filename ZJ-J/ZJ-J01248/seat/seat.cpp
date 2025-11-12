#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000],k,s,r,c;
bool cmp(int i,int j){
	return i>j;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i)cin>>a[i];
	k=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;++i)
		if(a[i]==k){
			c=(i-1)/n+1;
			s=i-(c-1)*n;
			if(c%2==0)r=n+1-s;
			else r=s;
			break;
		}
	cout<<c<<' '<<r;
	return 0;
}
