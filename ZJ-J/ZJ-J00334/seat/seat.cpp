#include<bits/stdc++.h>
using namespace std;
const int N=201;
int n,m,a[N],a1,c,r;
bool cmp(int A,int B){
	return A>B;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	a1=a[1];
	sort(a+1,a+1+n*m,cmp);
	c=1,r=1;
	for(int i=1;i<=n*m;i++){
		if(a[i]==a1){
			cout<<c<<" "<<r;
			return 0;
		}
		if(c%2){
			if(r==n){
				c++;
			}
			else{
				r++;
			}
		}else{
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
