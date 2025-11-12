#include <bits/stdc++.h>
using namespace std;
int n,m,b,a[205],c;
int x,y; 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	b=a[1];
	sort(a+1,a+1+n*m);
	x=1;y=1;
	if(a[n*m]==b){
		cout<<1<<" "<<1;
		return 0;
	}
	c=1;
	for(int i=n*m-1;i>=1;i--){
		if(y<m and c==1){
			y++;
			if(a[i]==b){
				cout<<x<<" "<<y;
				return 0; 
			}
			continue;
		}
		if(y==m and c==1){
			x++;
			c=2;
			if(a[i]==b){
				cout<<x<<" "<<y;
				return 0; 
			}
			continue;
		}
		if(y==1 and c==2){
			x++;
			c=1;
			if(a[i]==b){
				cout<<x<<" "<<y;
				return 0; 
			}
			continue;
		}
		if(y<=m and c==2){
			y--;
			if(a[i]==b){
				cout<<x<<" "<<y;
				return 0; 
			}
			continue;
		}
	}
	return 0;
} 
