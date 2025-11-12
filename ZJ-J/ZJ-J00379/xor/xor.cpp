#include<bits/stdc++.h>
using namespace std;
int n, k, a[500010], ans[500010], pos, sum;
unordered_map<int,int>mp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans[i]=a[i]^ans[i-1];
		if(!mp[ans[i]]){
			if(ans[i]!=k){
				mp[ans[i]^k]=i+1;
				continue;
			}
			if(pos==0){
				pos=i;
				sum++;
			}
			mp[0]=i+1;
			continue;
		}
		if(mp[ans[i]]<=pos){
			mp[ans[i]^k]=i+1;
		} 
		else{
			sum++;
			mp[ans[i]^k]=i+1;
			pos=i;
		}
	}
	cout<<sum;
	return 0;
} 
