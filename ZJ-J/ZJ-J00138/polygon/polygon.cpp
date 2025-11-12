#include<bits/stdc++.h>
using namespace std;
int n,a[10005],r=0;
int c=INT_MIN;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];       
    if(n<3) cout<<"0";
    else if(n==3){
    	for(int i=1;i<=n;i++){
		    c=max(c,a[i]);
		    r+=a[i];}
		if(2*c>=r) cout<<"0";
		else cout<<"1";}
	return 0;
}
