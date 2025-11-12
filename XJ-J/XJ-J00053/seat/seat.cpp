#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],R;

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	R=a[1];
	sort(a+1,a+n*m+1,cmp);
	int x;
	for(int i=1;i<=n*m;i++)
		if(a[i]==R)
			x=i;
	int lie=(x-1)/m+1;
	int hang=(lie%2==1)?(x%n?x%n:n):(x%n?n-x%n+1:1);
	cout<<lie<<' '<<hang;
	return 0;
}
