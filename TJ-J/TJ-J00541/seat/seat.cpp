#include<bits/stdc++.h>
using namespace std;
int n,m;
int a;
int t[1005];
int c=1,r=1;
bool f;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>t[i];
	}
	a=t[1];
	sort(t+1,t+1+n*m);
	for(int i=n*m;i>=1;i--){
		if(t[i]==a){
			cout<<c<<' '<<r;
			return 0;
		}
		if(!f){
			if(r==n){
				c++;//lie
				f=1;
			}else{
				r++;//hang
			}
		}else{
			if(r==1){
				c++;
				f=0;
			}else{
				r--;
			}
		}
	}
	return 0;
}
