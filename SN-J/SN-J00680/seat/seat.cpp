#include<bits/stdc++.h>
using namespace std;
int a[105];
bool c(int p,int q){
	return p>q;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,w,j=1;
	cin>>n>>m;
	int u=n*m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			w=a[i];
		}
	}
	sort(a+1,a+u+1,c);
	for(int i=1;i<=n;i++){
		if(a[i]=w){
			cout<<i<<" "<<1;
			return 0;
		}
	}
	return 0;
}
