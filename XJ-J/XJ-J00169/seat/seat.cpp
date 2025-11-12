#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int k=a[0];
	sort(a,a+(n*m),cmp);
	int xb;
	for(int i=0;i<m*n;i++){
		if(a[i]==k){
			xb=i;
			break;
		}
	}
	xb++;
	if(xb/n%2==0){
		if(xb%n!=0){
			cout<<xb/n+1<<' '<<xb%n;
		}else{
			cout<<xb/n<<' '<<1;
		}
	}else{
		if(xb%n!=0){
			cout<<xb/n+1<<' '<<n-xb%n+1;
		}else{
			cout<<xb/n<<' '<<n;
		}
	}
	return 0;
}
