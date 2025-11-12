#include<bits/stdc++.h>
using namespace std;
long long n,m,R,id,x,y,a[101];
bool cmp(long long x,long long y){
    return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	R=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	    if(a[i]==R){
		    id=i;
			break;
		}
	x=id/(2*n)*2,y=id%(2*n);
	if(y>0)x++;
	if(y>n)x++;
	if(y==0)y=2*n;
	cout<<x<<' '<<min(y,2*n-y+1);
}
