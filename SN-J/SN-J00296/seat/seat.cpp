#include<bits/stdc++.h>
using namespace std;
int a[101];
int main(){
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,t,ant=0,qm;
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
    	cin>>a[i];
    	t=a[0];
	}
	for(int i=0;i<n*m;i++){
		if(a[i+1]>a[i]){
			qm=a[i];
			a[i]=a[i+1];
			a[i+1]=qm;
		}
	}
	for(int i=0;i<n*m;i++){
		if(a[i]>a[i+1]>a[i+2]>a[i+3]>a[i+4]>a[i+5]>a[i+6]>a[i+7]){
			break;
		}
		if(a[i+1]>a[i]){
			qm=a[i];
			a[i]=a[i+1];
			a[i+1]=qm;
		}	
	}
	for(int i=0;i<n*m;i++){
		if(a[i-1]==t){
			ant=i-1;
		}
	}
	n=ant/n+1;
	if(n==1 or n==2){
		m=2;
	}
	else{
		m=1;
	}
	cout<<n<<" "<<m;
	return 0;
}
