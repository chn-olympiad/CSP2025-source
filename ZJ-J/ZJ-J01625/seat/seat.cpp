#include<bits/stdc++.h>
using namespace std;
int n,m;
int x,y;
int r;
int s=0;
long long a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		s++;
		if(a[i]==r){
			break;
		}
	}
	y=0;
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				y++;
				if(y==s){
					cout<<j<<" "<<i;
					break;
				}
			}
		}
		else {
			for(int i=n;i>=1;i--){
				y++;
				if(y==s){
					cout<<j<<" "<<i;
					break;
				}
			}
		}
	}
	return 0;
}
