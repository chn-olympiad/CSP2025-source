#include<bits/stdc++.h>
using namespace std;
int n,m,c,r,g,a[105],up;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	g=a[1];
	sort(a+1,a+(n*m)+1,[](int i,int j){return i>j;});
	c=0;r=1;up=0;
	for(int i=1;i<=n*m;i++){
		if(up){
			c--;
			if(c<1){
				r++;
				c=1;
				up=0;
			}
		}
		else{
			c++;
			if(c>n){
				r++;
				c=n;
				up=1;
			}
		}
		if(a[i]==g){
			cout<<r<<' '<<c<<'\n';
			return 0;
		}
	}
	return 0;
}
