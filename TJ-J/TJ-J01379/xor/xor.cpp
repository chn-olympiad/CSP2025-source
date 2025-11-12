#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
 	int n,k;
 	int flag;
 	cin>>n>>k;
 	int a[500050];
 	for(int i=1;i<=n;i++){
 		cin>>a[i];
 		if(a[i]==1){
 			flag+=1;
		 }
	}
	if(flag==n){
		if(k!=1){
			cout<<0;
		}else if(k==1){
			cout<<n*(n+1)/2;
		}
		
	}else if(k==0){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				cnt++;
			}
		}
		cout<<cnt;
	}
	return 0;
}

