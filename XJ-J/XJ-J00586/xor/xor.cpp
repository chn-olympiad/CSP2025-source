#include<bits/stdc++.h>
using namespace std;
int n,k,cnt=0,a[500005];
bool flag=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			flag=1;
		}
	}
	if(k==0&&flag==0){
		cout<<"0";
		return 0;		
	}		
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			cnt++;
		}
	}	
	cout<<cnt;
	return 0;
} 
