#include <bits/stdc++.h>
using namespace std;
int x[200005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cnt=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(x[i]==0){
				cnt++;
			}
		}
		cout<<cnt;	
	}
	if(k==1){
		for(int i=1;i<=n;i++){
			if(x[i]==1){
				cnt++;
			}
		}
		cout<<cnt;	
	}
	return 0;
} 
