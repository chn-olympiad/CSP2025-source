#include <bits/stdc++.h>
using namespace std;
int n,k;
int x[50005],a,b;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		if(x[i]==1){
			a++;	
		} 
		if(x[i]==1 and x[i-1]==1 and (x[i-2]!=1 or(x[i-3]==1 and x[i-2]==1))){
			b++;
		}
		if(x[i]==0) b++;
	}
	if(a==n){
		if(k==1){
			cout<<a;
			return 0;
		}
		if(k==0){
			cout<<a/2;
			return 0;
		}
		cout<<0;
		return 0;
	}
	if(k==0) cout<<b;
	if(k==1) cout<<a;
	return 0;
}
