#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[1145];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}int p=a[1];
	sort(a+1,a+n*m+1,cmp);
	int x;
	for(int i=1;i<=n*m;i++){
		if(a[i]==p)x=i;
	}
	int s=x%(2*n);
	int c=(x-1)/n+1,r;
	if(s<=n)r=s;
	else r=2*n-s+1;
	cout<<c<<" "<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

