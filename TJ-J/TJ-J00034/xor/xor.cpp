#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int n,k;
	cin>>n>>k;
	short s[500001];
	short x[500001]={0};
	int b=1;
	int ans=0;
	for(int i = 1;i <= n;i++){
		cin>>s[i];
		x[i]=x[i-1]^s[i];
		//cout<<x[i]<<endl;;
		for(int j = b;j <= i;j++){
			if(b>i)continue;
			if((x[i]^x[j-1])==k){
				b=i+1;
				ans++;
				//cout<<j<<" "<<i<<" "<<(x[i]^x[j-1])<<endl;
			}
		}
	}
	cout<<ans;
	return 0;
}
