#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int a[1142];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,t;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int tnum=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==tnum)t=i;
	}
	if(t%(2*n)<=n)cout<<ceil(1.0*t/n)<<" "<<(t-1)%n+1;
	else cout<<ceil(1.0*t/n)<<" "<<n-(t-1)%n;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
