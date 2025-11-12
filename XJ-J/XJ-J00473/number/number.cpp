#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	char n,x,y,t;
	cin >> n >> x >> y >> t;
	for(int i = 1;i <= n;i++){
		if(n>=1 and n<=9){
		   if(x>=1 and x<=9){
		    if(y>=1 and y<=9){
		    if(y>t){
		    	t = y;
			}else if(x > n){
				n= x;
			}else {
				x=n;
			}
		}
		}				
		} 				
		}
	}
	cout << y << x << n;
	return 0;
} 
