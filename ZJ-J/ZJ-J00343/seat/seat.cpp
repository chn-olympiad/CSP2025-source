#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1])cnt++;
	}
	int r=cnt/(2*n)*2+1,w=cnt%(2*n)+1;
	if(w>n)w=2*n+1-w,r++;
	cout<<r<<" "<<w;
	return 0;
}
