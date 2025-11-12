#include<bits/stdc++.h>
using namespace std;
int n,m,c=1,r=1,s=0;
int a[10005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	s=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==s){
			cout<<c<<" "<<r;
			break;
		}
		if(c%2==0){
			r--;
			if(r==0){
				r=1;
				c++;
			}
		}
		else{
			r++;
			if(r==n+1){
				r=n;
				c++;
			}
		}
	}
	return 0;
}