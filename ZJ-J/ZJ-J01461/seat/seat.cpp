#include<bits/stdc++.h>
using namespace std;

int n,m;
int c=1,r=1;
int t;
int a[105];
int tmp;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	tmp=a[1];
	sort(a+1,a+n*m+1);
	t=n*m+1;
	while(1){
		t--;
		if(a[t]==tmp){
			cout<<c<<" "<<r;
			break;
		}
		if(c%2==1){
			if(r==n){
				c++;
			}
			else{
				r++;
			}
		}
		else{
			if(r==1){
				c++;
			}
			else{
				r--;
			}
		}
	}
	return 0;
}