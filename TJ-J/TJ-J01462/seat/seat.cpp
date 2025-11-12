#include<bits/stdc++.h>
using namespace std;
int m,n,c=1,r=1,a[105],b[11][11];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int s=n*m,w;
	for(int i=1;i<=s;i++) cin>>a[i];
	w=a[1];
	for(int i=1;i<=s;i++){
		if(a[i]>a[i-1]) swap(a[i],a[i-1]);
	}
	int e;
	for(int i=1;i<=s;i++){
		if(a[i]==w) e=i;
	}
	for(int j=0;j<e;j++){
		if(r<n&&c%2==1) r++;
		else if(r==n&&c%2==1) c++;
		else if(r==n&&c%2==0) r--;
		else if(r>1&&c%2==0) r--;
		else if(r==1&&c%2==0) c++;	
	}
	cout<<c<<' '<<r;
	return 0;
} 
