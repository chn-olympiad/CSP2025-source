#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,k,a[N],flag=1,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=0;
	}
	if(flag) cout<<n/2;
	else{
		for(int i=1;i<=n;){
			if(a[i]==k) ans++,i+=1;
			else if(a[i+1]^a[i]==k) ans++,i+=2;
			else i=i+1;
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout); 
	
    return 0;
}


