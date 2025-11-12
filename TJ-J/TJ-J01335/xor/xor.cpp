#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,ans=0;
    cin>>n>>k;
    vector<int>v(n+1);
    vector<int>s(n+1);
    vector<int>f(n+1);
    for(int i=1;i<=n;i++){
    	cin>>v[i];
    	s[i]=s[i-1]^v[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j<i && i==1)f[j]=f[j-1];
			else if(j<i);
			else if((s[j]^s[j-i])==k){
				int q=f[j-i]+1;
				f[j]=max(max(q,f[j]),f[j-1]);
			}
			else if(i==1)f[j]=f[j-1];
			else f[j]=max(f[j],f[j-1]);
		}
	}
	cout<<f[n];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
