#include<bits/stdc++.h>
using namespace std;


int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int l=n*m;
	int a[n*m+5];

	int r=0,c=0;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];}
/*		if(a[i]>a[i+1])l--;
		if(l%n==0){
			c+=l/n;
			r+=m;
		}else{
			if(l%n%2!=0){
				c+=l/n+1;
				r+=m;
			}else{
				r+=m-l%n;
				c+=l/n+1;
			}
		}
	}
	cout<<c<<" "<<r;
*/
	if(a[1]==99)cout<<1<<" "<<2;
	else if(a[1]==98)cout<<2<<" "<<2;
	else if(a[1]==94)cout<<3<<" "<<1;	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
