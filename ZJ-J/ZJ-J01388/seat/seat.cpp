#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using namespace std;
int a[110];
bool cmp(int x,int y){
	return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
 	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int ans=a[1];
	sort(a+1,a+n*m+1,cmp);
//	cout<<ans<<endl;
	int r=1,c=1,z=1;
	bool f=0;//f=0 down,f=1 up
	while(z<=n*m){
		if(a[z]==ans){
			cout<<c<<" "<<r<<endl;
			return 0;
		}
		if(r==n){
			f=1;
			c++;
			z++;
		}
		if(a[z]==ans){
			cout<<c<<" "<<r<<endl;
			return 0;
		}
		if(r==1){
			f=0;
			if(c!=1){
				c++;
				z++;
			}
		}
		if(a[z]==ans){
			cout<<c<<" "<<r<<endl;
			return 0;
		}
		r+=(f?-1:1);
		z++;
		if(a[z]==ans){
			cout<<c<<" "<<r<<endl;
			return 0;
		}
	}
    return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92
*/
//AFO.
//OK 100 pts ^_^