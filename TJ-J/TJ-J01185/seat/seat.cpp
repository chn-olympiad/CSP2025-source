#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int n,m,a[105],x,maxn=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	int r=a[1];
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=n*m;j++){
			if(a[i]<a[i+1]){
				swap(a[i],a[i+1]);
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			r=i;
		}
	}
	int l,h;
	if(r%n!=0){
		l=r/n+1;
	}
	else{
		l=r/n;
	}
	if(l%2==0){
		h=n-r%n+1;
	}
	else{
		if(r==n){
			h=r%n+1;
		}
		else{
			h=n;
		}
	}
	cout << l<< " " <<h;
	return 0;
}
