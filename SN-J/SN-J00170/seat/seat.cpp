#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	int abc=n*m;
	sort(a+1,a+abc+1);
	int p=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			p=i;
			break;
		}
	} 
	p=abc+1-p;
	if(p%n==0){
		if(p/n%2==0){
			cout<<p/n<<" "<<1;
			return 0; 
		}
		else{
			cout<<p/n<<" "<<n;
			return 0; 
		}
	}
	int p1=p-p%n;
	if(p1/n%2==0){
		cout<<p1/n+1<<" "<<p%n;
		return 0; 
	}
	else{
		cout<<p1/n+1<<" "<<n-p%n+1;
		return 0;
	}
	
	return 0; 
}

