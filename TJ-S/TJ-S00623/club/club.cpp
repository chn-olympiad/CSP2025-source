#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		int n,a[100005],b[100005],c[1000005],a1,b1,c1,a2,b2,c2;
		cin >> n;
		for(int i = 1;i <= n;i++){
				cin >> a[i] >> b[i] >> c[i];
		}
		a1 = a[1],b1 = b[1],c1 = c[1];
		for(int i = 1;i <= n;i++){
			if(a[i] > a1){
				a2 = a1;
				a1 = a[i];	
			}
		}
		for(int i = 1;i <= n;i++){
			if(b[i] > b1){
				b2 = b1;
				b1 = b[i];	
			}
		}
		for(int i = 1;i <= n;i++){
			if(c[i] > c1){
				c2 = c1;
				c1 = c[i];	
			}
		}
		cout << a1+b1+c1+a2+b2+c2;
	}
	return 0;
}
