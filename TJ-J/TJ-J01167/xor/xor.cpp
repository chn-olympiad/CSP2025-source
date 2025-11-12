#include<bits/stdc++.h>
using namespace std;
int a[500005];
int n,k; 
int ans;
int yyeess;
int now;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		cout<<1;
		fclose(stdin);
		fclose(stdout);		
		return 0;
	}
	for(int i=1;i<=n;i++){
		now=now|a[i];
		yyeess=now&k;
		if(yyeess==k){
			ans++;
			now=0;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
