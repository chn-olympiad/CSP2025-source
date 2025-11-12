#include<bits/stdc++.h>
using namespace std;
int n,m,a[10005],t;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	t=a[1];
	sort(a+1,a+n*m+1,cmp);
	int i=0,j=1;
	for(int x=1;x<=n*m;x++){
		if(j%2==1)i++;
		else i--;
		if(i>n)i=n,j++;
		if(i<1)i=1,j++;
		if(a[x]==t){
			cout<<j<<" "<<i;
			return 0;
		}
	}
	return 0;
}
