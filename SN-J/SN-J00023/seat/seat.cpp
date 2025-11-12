#include<bits/stdc++.h>
using namespace std;
int a[110],n,m,a1,id;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	a1=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==a1){
		    id=i;
		    break;
		}
	}
	int x=id/n,y=id%n;
    if(y==0){
    	if(x%2==1) cout<<x<<' '<<n;
    	else cout<<x<<' '<<1; 
	}else{
	    x++;
		if(x%2==1) cout<<x<<' '<<y;
	    else cout<<x<<' '<<n+1-y;
	}
	return 0;
}
