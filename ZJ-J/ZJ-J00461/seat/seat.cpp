#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],cnt,c,r,tot;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	cnt=a[1];
	sort(1+a,1+a+n*m,cmp);
	c=1,r=1,tot=1;
	while(1){
		if(a[tot]==cnt) break;
		if(r%2==1){
			if(c==n){
				r++;
			}
			else{
				c++;
			}
		}
		else{
			if(c==1){
				r++;
			}
			else{
				c--;
			}
		}
		tot++;
	}
	cout<<r<<" "<<c;
	return 0;
}