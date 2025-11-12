#include<bits/stdc++.h>
using namespace std;
int n,m,k=1,op,l;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>op;
	for(int i=2;i<=n*m;i++){
		int a;
		cin>>a;
		if(a>op){
			k++;
		}
	}
//	cout<<k<<endl;
	if(k%n==0) l=k/n;
	else l=k/n+1;
	cout<<l<<" ";
	if(l%2==1)
		cout<<k-(l-1)*n;
	else{
		cout<<n-(k-(l-1)*n)+1;
	}
	return 0;
}