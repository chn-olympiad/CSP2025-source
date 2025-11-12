#include<bits/stdc++.h>
using namespace std;
int n,m,ans=1,P;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>P;
	for(int i=2;i<=n*m;i++){
		int a;
		cin>>a;
		if(a>P)ans++;
	}
	int l=ans/n;
	int r=ans%n;
	if(r>=1)l++;
	if(r==0)r=n;
	if(l%2==0){
		r=n-r+1;
	}
	cout<<l<<" "<<r;
	return 0;
}
//Ä§Êõ¼¼ÇÉ£¡ 
