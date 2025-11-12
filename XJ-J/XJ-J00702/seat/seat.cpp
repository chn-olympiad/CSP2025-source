#include<bits/stdc++.h>
using namespace std;

int main(){
	int n=0,m=0,a[105],r=0,b[105];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		b[i]=a[n*m-i+1];
	}
	for(int i=1;i<=n*m;i++){
		if(r==b[i]){
			r=i;
			break;
		}
	}
	if(r%n==0){
		if((r/n)%2==1){
			cout<<r/n<<" "<<m;
		}
		else{
			cout<<r/n<<" "<<"1";
		}
	}
	else{
		if((r/n+1)%2==1){
			cout<<r/n+1<<" "<<r%m;
		}
		else{
			cout<<r/n+1<<" "<<m-r%m+1;
		}
	}
}
