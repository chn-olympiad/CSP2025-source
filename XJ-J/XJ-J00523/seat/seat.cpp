#include<bits/stdc++.h> 
using namespace std;
const int N=3e3+7;
int a[N],x=1;
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	for(int i=2;i<=n*m;i++){
		if(a[1]<a[i]) x++;
	}
	int p=(x+n-1)/n;
	int q=x%n;
	if(p%2==0){
		if(q==0) q=1;
		else q=n+1-q;
	} 
	else{
		if(q==0) q=n;
		else q=q;
	} 
	cout<<p<<" "<<q;
	return 0;
}
