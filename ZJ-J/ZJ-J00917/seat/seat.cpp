#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define faster ios::sync_with_stdio(0);cin.tie(0);
using namespace std;
int n,m,ans;
int a[200];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	ans=a[1];
	if(n==1&&m==1){
		cout<<1<<' '<<1;
		return 0;
	}
	sort(a+1,a+1+n*m,cmp);
	int c=1,r=0,l=0,f0=0,f1=0;
	while(c<=n){
		if(f1){
			l++;
			if(a[l]==ans){
				cout<<c<<' '<<r;
				break;
			}
			f1=0;
			continue;	
		}
		if(f0){
			r--;
		}
		else{
			r++;
		}
		if(r==m+1){
			r=m;
			c++;
			f0=1;
		}
		l++;
		if(a[l]==ans){
			cout<<c<<' '<<r;
			break;
		}
		if(r==1&&c>1){
			c++;
			f0=0;
			f1=1;
		}
	}
	return 0;
}
