#include<bits/stdc++.h>
using namespace std;
int n,m,c=1,r=1,cj,cjr,l=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>cjr;
	for(int i=0;i<n*m-1;i++){
		cin>>cj;
		if(l==1||l%2!=0){
			if(cjr<cj) r++;
			if(r>n){
				c++;
				l++;
			}
		}
		if(l%2==0){
			if(cjr<cj) r--;
			if(r<1){
				r++;
				c++;
				l++;
			}
		}
	}
	cout<<c<<' '<<r;
	return 0;
}
