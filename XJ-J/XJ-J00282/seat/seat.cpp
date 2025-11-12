#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,d[102],f,c=1,r=1 ;
	cin >> n>>m;
	f=n*m;
	for(int i=1;i<=f;i++){
		cin >> d[i];
	}
	for(int i=1;i<=f;i++){
	
		if(d[1]>d[i]){
			c=c+0,r=r+0;
		}	
		if(d[1]<d[i]){
			c=c+0,r=r+1;
			if(r==n){
				c=c+1;	
				if(c==m&&r==n){
						break;
					}
					r=r-1;
					if(r==1){
						c=c+1;
						if(c==m&&r==n){
							c=c-1;
							break;
						}
					}
			}
		}
	}
	cout << c<<" "<<r;
	return 0;
}
