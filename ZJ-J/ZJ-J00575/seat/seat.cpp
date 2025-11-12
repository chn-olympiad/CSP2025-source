#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=105;
int n,m,a[MAXN],q,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int k=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==k) q=n*m-i+1;
	}
	//cout<<q<<"#";
	if(q%n==0){
		r=q/n;
		if(r%2==0) c=1;
		else c=n;
	}
	else{
		r=q/n+1;
		if(r%2==0) c=n-q%n+1;
		else c=q%n;
	}
	cout<<r<<" "<<c;
	return 0;
}
