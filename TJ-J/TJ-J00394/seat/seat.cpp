#include <bits/stdc++.h>
using namespace std;
int p,a[100],n,m,t,s;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	s=n;
	cin>>p;
	a[p]=1;
	int r=n*m;
	for(int i=0;i<r-1;i++){
		int y;
		cin>>y;
		a[y]=1;
	}for(int i=100;i>=p;i--){
		if(a[i]==1) t++;
	}
	n=s;
	int b=0;
	if(t%n==0){
		b=t/n-1;
	}else b=t/n;
	if(b%2==0){
		cout<<b<<" "<<m*b-t+1;
	}else if(b%2!=0){
		cout<<b<<" "<<t-m*(b-1);
	}
	return 0;
}
