#include<bits/stdc++.h>
using namespace std;
int ppo=0;
int a[5000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k)ppo++;
	}
	int o;
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			ans++;
			a[i]=0;
			continue;
		}
		else {
			o=a[i]xor a[i-1];
			a[i]=o;
			if(a[i]==k){
				ans++;
				a[i]=0;
			}
		}
	}
	if(ppo>ans)cout<<ppo;
	else cout<<ans;
	return 0;
} 
