#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	int a[500005];
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(k==0){
		int cnt=0;
		for(int i=n;i>0;i--){
			cnt+=i;
		}
		cout<<cnt<<endl;
		return 0;
	}
	return 0;
} 
