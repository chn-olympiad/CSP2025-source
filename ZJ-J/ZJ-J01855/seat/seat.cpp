#include<bits/stdc++.h>
using namespace std;
int n,m,a[200],k=1,l,h;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1])k++;}
	if(k%n==0){
		l=k/n;
		if(l%2==1){
			h=n;	
		}
		else{
			h=1;	
		} 
	}
	else
	{
		l=k/n+1;
		if(l%2==1){
			h=k%n;
		}
		else{
			h=n-(k%n)+1;
		}
	}
	cout<<l<<" "<<h; 
	return 0;
}
