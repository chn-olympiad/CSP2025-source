#include <bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,cnt=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]){
			cnt++;
		}
	} 
	int c,r;
	c=(cnt+n-1)/n;
	if(c%2 != 0){
		if(cnt%n == 0){
			r=n;
		}
		else{
			r=cnt%n;
		}
	}
	else{
		if(cnt%2 == 0){
			r=1;
		}
		else{
			r=(n+1)-(cnt%n); 
		}
	}
	cout<<c<<" "<<r;
	return 0;
} 
