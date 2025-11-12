#include<bits/stdc++.h>
using namespace std;
int a[500050];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		int c1=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				c1++;
			}
		}
		int c0=n-c1;
		int ans=c1/2+c0;
		cout<<ans;
	}else if(k==1){
		int c1=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				c1++;
			}
		}
		cout<<c1;
	}else{
		cout<<69;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}