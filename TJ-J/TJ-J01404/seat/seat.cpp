#include<bits/stdc++.h>
using namespace std;
int a[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,c=1,r=1,s=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--){
		if(s!=a[i]){
			if(r==1 && c%2==0){
				c++;
			}
			else if(c%2==0){
				r--;
			}
			else if(r==n){
				c++;
			}
			else{
				r++;
			}
		}
		else{
			break;
		}
	}
	cout<<c<<" "<<r;
	return 0;
} 
