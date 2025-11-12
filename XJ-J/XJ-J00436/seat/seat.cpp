#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m; 
	cin>>n>>m;
	int x=n*m;
	int a[x];
	for(int i=1;i<=x;i++){
		cin>>a[i];
	}
	int k=a[1],b;
	sort(a,a+x+1);
	int j=0;
	for(int i=x;i>0;i--){
		if(a[i]==k){
			b=j;
			break;
		}
		j++;
	}
	int h=(b/n),l=b-(b%n);
	if(h%2!=0){
		h++;
	}
	cout<<h<<" "<<l;
	return 0;
}
