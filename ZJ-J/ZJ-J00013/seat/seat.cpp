#include<bits/stdc++.h>
using namespace std;
int n,m,c,r;
struct N{
	int a,i;
}p[105];
bool cmp(N A,N B){
	return A.a>B.a;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>p[i].a;
		p[i].i=i;
	}
	sort(p+1,p+n*m+1,cmp);
	int t;
	for(int i=1;i<=n*m;i++){
		if(p[i].i==1){
			t=i;
			break;
		}
	}
	c=ceil(1.0*t/n);
	r=t%n;
	if(r==0)r=n;
	if(c%2==0){
		r=n-r+1;
	}
	cout<<c<<" "<<r;
}