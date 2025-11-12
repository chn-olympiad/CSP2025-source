#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,ans;
	cin >>n >>m;
	int a[n][m]={};
	int b[n*m]={};
	for(int i=0;i<n*m;i++){
		cin >>b[i];
	}
	ans=b[0];
	sort(b+0,b+n*m,greater<int>());
	for(int i=0;i<n*m;i++){
		if(b[i]==ans){
			int tep=i%n,tmp=i/n;
			if(tmp%2==0){
				cout <<tmp+1<<" "<<tep+1;
			}
			else{
				cout <<tmp+1<<" "<<n-tep;
			}
		}
	}
	return 0;
} 
