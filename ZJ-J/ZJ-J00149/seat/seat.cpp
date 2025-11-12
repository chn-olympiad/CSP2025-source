#include<bits/stdc++.h>
using namespace std;
int a[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
//	freopen("ans.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int l=n*m;
	for(int i=1;i<=l;i++){
		cin>>a[i];
	}
	int r=a[1];
	int v=1;
	for(int i=2;i<=l;i++){
		if(a[i]>r)v++;
	}
//	cout<<v;
//	^ture^
	if(v==1)cout<<1<<" "<<1;
//	^ture^
	else if(v%n==0){//2x+1,n or 2x,1
		cout<<v/n<<" ";
		if((v/n)%2==0){
			cout<<1;
		}
		else if((v/n)%2!=0){
			cout<<n;
		}
	}
//	^ture^
	else if(v%n==1){//2x+1,1 or 2x,n
		cout<<v/n+1<<" ";
		if((v/n+1)%2==0){
			cout<<n;
		}
		else if((v/n+1)%2!=0){
			cout<<1;
		}
	}
//	^ture^
	else if(v%n!=0){
		cout<<v/n+1<<" ";
		if((v/n+1)%2==0){
			cout<<n-v%n+1;
		}
		else if((v/n+1)%2!=0){
			cout<<v%n;
		}
	}
	return 0;
}