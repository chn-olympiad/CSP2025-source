#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m,ans[105];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>ans[i];
	}
	int R=ans[1];
	sort(ans+1,ans+n*m+1);
	for(int i=1;i<=n*m;i++){
		if (ans[i]==R){
			if (n==1){
				cout<<n*m-i+1<<" "<<1;
				break;
			}
			if (m==1){
				cout<<1<<" "<<n*m-i+1;
				break;
			}
			if(n*m-i+1<=n){
				cout<<1<<" "<<n*m-i+1;
				break;
			}
			if (n*m-i+1==n*m){
				if(m%2==1){
					 cout<<m<<" "<<n;
				    break;
				}  
				else {
					cout<<m<<" "<<1;
				    break;
				}
			}
			if(m==2){
				int nb=n*m-i+1;
				cout<<2<<" "<<n-(nb-n)+1;
			}
		}
	}
	return 0;
} 

