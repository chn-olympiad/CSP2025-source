#include<bits/stdc++.h>
using namespace std;
int n,k,ans=2;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    
	if(k==0){
		ans=1;
		for(int i=1;i<n;i++)
			if(a[i]==a[i+1]){
				ans=2;
				break;}
		}
	cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
