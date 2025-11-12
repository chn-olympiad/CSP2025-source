#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> a(n*m+1);
	for(int i=0;i<n*m;i++) cin>>a[i];
	int x=a[0],c=0,r=1,ma=0,nu=n*m,maid=0;
	while(nu--){
		int f=1;
		for(int i=0;i<n*m;i++){
			if(f){
				c%=n;c++;
				if(c==4 and f){
					r++;
					f=0;
				}
			}
			else{
				c%=n;c++;
				if(c==1 and !f){
					r++;
					f=1;
				}				
			}
			if(a[i]>ma){
				ma=a[i];
				maid=i;
			}
		}
		if(ma==x) return cout<<r<<' '<<c,0;
		ma=0;a[maid]=0;
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
} 
