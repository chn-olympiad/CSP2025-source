#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,k,ni[N],ans=0;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>ni[i];
		if(ni[i]==0){
			ans++;
		}
	}
	if(k==0){
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
