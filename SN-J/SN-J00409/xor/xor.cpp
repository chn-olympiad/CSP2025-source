#include <bits/stdc++.h>
using namespace std;
int n,k,a[500010],cnt0=0,cnt1=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			cnt0++;
		}else{
			cnt1++;
		}
	}
	if(k==0){
		cout<<cnt0<<endl;
	}else{
		cout<<cnt1<<endl; 
	} 
	return 0;
}
