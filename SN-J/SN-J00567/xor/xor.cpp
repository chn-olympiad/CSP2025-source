/*李牧泽 SN-J00567 西安滨河学校*/
#include<bits/stdc++.h>
using namespace std;
#define FI(x) freopen(x".in","r",stdin)
#define FO(x) freopen(x".out","w",stdout)
int a[500005];
int main(){
	FI("xor");
	FO("xor");
	int n,k,x=0,a,b=-1,c,d;
	cin>>n>>k;
	for (int i=0;i<n;i++){
		cin>>a;
		if (a==k){
			x++;
			b=-1;
			continue;
		}
		d=a;
		if (b!=1) {
			c=a;
			b=1;
			continue;
		}
		c^=d;
		if (c==k){
			x++;
			b=-1;
			continue;
		}
	}
	cout<<x;
	return 0;
} 
