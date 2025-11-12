#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int pos=a[1],poss=0;
	sort(a+1,a+n*m+1);
	reverse(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==pos){
			poss=i;
			break;
		}
	}
	int l=poss%n,r=poss/n;
	if(l!=0){
		r++;
		cout<<r<<" ";
		if(r%2==1){
			cout<<l;
		}
		else{
			cout<<n-l+1;
		}
	}
	else{
		cout<<r<<" ";
		if(r%2==1){
			cout<<n;
		}
		else{
			cout<<1;
		}
	}
	return 0;
}