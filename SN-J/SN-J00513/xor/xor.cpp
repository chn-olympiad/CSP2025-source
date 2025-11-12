#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int s[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	int ans=0;
	if(k==0){
		for(int i=1;i<=n;i++){
			if(s[i]==0){
				ans++;
			}
		}
	}else{
		int num=0;
		for(int i=1;i<=n;i++){
			num+=s[i];
			if(num==k){
				ans++;
				num=0;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
