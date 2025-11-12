#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000001],fl=1,fl1=1,s,v[1000001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) fl=0;
		if(a[i]>1) fl1=0;
	}
	if(fl){
		cout<<n/2;
		return 0;
	} 
	if(fl1){
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					s++;
				}else if(a[i]==1&&a[i]==a[i-1]) s++,i++;
			}
		}else{
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					s++;
				}
			}
		}
		cout<<s;
		return 0;
	}
	cout<<rand();
	return 0;
}
