#include<bits/stdc++.h>
using namespace std;
int cnt=1,n,m,c=1,r=1,a[111];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]){
			cnt++;
		}
	}
	for(int i=1;i<=n*m;i++){
		if(i==cnt){
			cout<<r<<" "<<c<<"\n";
			break;
		}
		if(r%2==1){
			c++;
			if(c>n){
				c--;
				r++;
			}
		}
		else{
			c--;
			if(c==0){
				c++;
				r++;
			}
		}
	}
	return 0;
}
