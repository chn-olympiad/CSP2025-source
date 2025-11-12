#include <bits/stdc++.h>
using namespace std;
int n,m,a[1000005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++)cin>>a[i];
	int r=a[1];
	sort(a+1,a+n*m+1,cmp);
	int f;
	for (int i=1;i<=n*m;i++)if (a[i]==r)f=i;
	int q=f/n;
	int y=f%n;
	if (f%n){
		q++;
		if (q%2)cout<<q<<" "<<y;
		else cout<<q<<" "<<n-y+1;
	}else {
		if (q%2)cout<<q<<" "<<n;
		else cout<<q<<" "<<1;
	}
	return 0;
} 
