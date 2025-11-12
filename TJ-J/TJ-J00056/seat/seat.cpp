#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);//////////////////////////////
	freopen("seat.out","w",stdout);
	
	int n,m,a[105],r=0,s=0;
	cin>>n>>m;
	int p=n*m,ansx=0,ansy=0;
	for(int i=1;i<=p;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a,a+p+1);
	for(int i=p;i>=1;i--){
		if(a[i]==r) s=p-i+1;
	}
	if(s%n==0){
		if(s/n==0){
			cout<<s/n<<" "<<1;
			return 0;
		}else{
			cout<<s/n<<" "<<n;
			return 0;
		}
		cout<<s/n<<" "<<n;
		return 0;
	} 
	
	if(s==1){
		ansx=1;
		ansy=1;
		cout<<ansx<<" "<<ansy;
		return 0;
	}
	if((s/n+1)%2==0){
		cout<<s/n+1<<" "<<n-(s%n)+1;
		return 0;
	}
	cout<<s/n+1<<" "<<s%n;

	return 0;
		
}
