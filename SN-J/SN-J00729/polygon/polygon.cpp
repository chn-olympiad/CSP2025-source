#include <bits/stdc++.h>
using namespace std;
int n,k,a[4],d;                                                                                                                                                                                                            
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]>k) k=i;
		}
		for(int i=1;i<=n;i++){
			if(i!=k){
			d=d+a[i];	
			}
		}
		if(d>k) cout<<"1";
		else cout<<"0";
	return 0;
}
