#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,ovo,a,cnt,x=1,y=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>ovo;
	for(int i=2;i<=n*m;i++){
		cin>>a;
		if(a>ovo){
			cnt++;
		}
	}
	while(cnt--){
		if(y%2==1){
			if(x==n){
				y++;
			}else{
				x++;
			}
		}else{
			if(x==1){
				y++;
			}else{
				x--;
			}
		}
	}
	cout<<y<<" "<<x;
	return 0;
}