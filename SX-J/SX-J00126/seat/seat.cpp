#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen ("seat.in","r",stdin);
	freopen ("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int nm=n*m;
	int a[n*m];
	for(int i=0;i<nm;i++){
		cin>>a[i];
	}
	int r=a[0];
	sort(a,a+nm);
    int b=0;
    for(int i=0;i<nm;i++){
		if(a[i]==r){
			b=nm-i;
			break;
		}
	}
	if(b%n==0){
		if((b/n)%2==1){
			cout<<b/n<<" "<<n;
		}else{
			cout<<b/n<<" "<<1;
		}
	}else{
		if((b/n+1)%2==1){
			cout<<b/n+1<<" "<<b-b/n*n;
		}else{
			cout<<b/n+1<<" "<<n+1-(b-b/n*n);
		}
	}


	return 0;
}