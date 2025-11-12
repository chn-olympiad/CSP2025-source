#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int x[n*m];
	for(int a=0;a<n*m;a++){
		cin>>x[a];
	}
	int s=x[0],q=0;
	for(int b=0;b<n*m;b++){
		if(x[b]>s){
			q++;
		}
	}
	q++;
	double l=double(q)/n;
	int l1,h;
	if(int(l)==l){
		l1=l;
	}
	else{
		l1=int(l)+1;
	}
	if(l1%2==0){
		h=n+1-q%n;
		if(h==n+1){
			h=1;
		}
	}
	else{
		h=q%n;
		if(h==0){
			h=n;
		}
	}
	cout<<l1<<" "<<h;
	return 0;
}
