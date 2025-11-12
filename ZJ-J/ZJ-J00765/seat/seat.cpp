#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[105],R;
int main(){
	freopen("seat.in","r",stdin);
	freopen("sean.out","w",stdout);
	cin>>n>>m;
	k=n*m;
	for(int i=1;i<=k;i++){
		cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+k+1);
	int c=1,r=1,i=k;
	while(c<=m&&r<=n){
		if(a[k--]==R)break;
		if(c%2==1&&r<n){
			r++;
		}
		else if((c%2==1&&r==n)||(c%2==0&&r<=1)){
			c++;
		}
		else if(c%2==0&&r>1){
			r--;
		}
	}
	cout<<c<<' '<<r;
	return 0;
}
