#include<bits/stdc++.h>
using namespace std;
int n,m,z[50],a[250];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) z[i]=i;
	int ji=n;
	for(int i=n+1;i<=n*2;i++) z[i]=ji,ji--;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int r=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			r=n*m-i+1;
			break;
		}
	}
	int l,h;
	l=(r-1)/(n*2);
	h=z[r-n*2*l];
	l=(r-1)/n+1;
	cout<<l<<" "<<h;
	return 0;
}
