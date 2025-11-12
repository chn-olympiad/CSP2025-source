#include<bits/stdc++.h>
using namespace std;
int a[500000+100];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int m,k;
	cin>>m>>k;
	int ans=0;
	for(int i=0;i<m;i++){
		cin>>a[i];
		if(a[i]==k)ans++;
	}
	if(k==0){
		for(int i=1;i<m;i++){
			if(a[i]==1&&a[i-1]==1){
				ans++;
				i++;
			}
		}
		cout<<ans;
	}
	else if(k==1) cout<<ans;
	else{
		int cnt=0;
		int yhh=a[0];
		int p=0;
		for(int i=1;i<m;i++){
			yhh^=a[i];
			if(yhh==k&&a[i+1]!=k){
				cnt++;
				yhh=a[i+1];
				i++;
				p=i+1;
			}
			else if(yhh==k&&a[i+1]==k){
				cnt++;
				yhh=a[i+2];
				i+=2;
				p=i+1;
			}	
			if(p+1!=m&&i+1==m&&yhh!=k){
				i=p+1;
				yhh=a[p+1];
			}
		}
		cout<<cnt;
	}
	return 0;
}
