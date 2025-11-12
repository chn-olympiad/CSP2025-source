#include<bits/stdc++.h>
using namespace std;
int a[10001],n,m,R;
bool cmp(int a,int b){
	return a>b;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;++i){
		if(a[i]==R){
			int c=i%(2*n),r=i/(n*2)*2;
			if(c<=n&&c!=0) cout<<r+1<<" ";
			else if(c!=0) cout<<r+2<<" ";
			else cout<<r<<" ";
			if(c<=n&&c!=0) cout<<c<<" ";
			else if(c!=0) cout<<n*2-c+1<<" ";
			else cout<<c+1<<" ";
		}
	}
	return 0;
}
