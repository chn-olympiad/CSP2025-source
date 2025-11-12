#include<bits/stdc++.h>
using namespace std;
int n,a[500010],k,pre_xor[500010];
bool vis[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	int ans=0,cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt+=a[i];
		if(a[i]==k){
			ans++;//qv1
			vis[i]=1;
		}
	}
	vector<int>v;
	for(int i=1;i<=n;i++){
		if(vis[i]){
			pre_xor[i]=0;
			v.clear();
			continue;
		}
		if(pre_xor[i]==k){
			ans++;
			v.clear();
			pre_xor[i]=0;
		}
		pre_xor[i]=a[i]^pre_xor[i-1];
		v.push_back(pre_xor[i]);
		if(!v.empty())
			for(int i=0;i<v.size();i++){
				if((v[i]^pre_xor[i])==k){
					ans++;
					v.clear();
					
					pre_xor[i]=0;
				}
			}
		
		
	}
	if(k==1&&cnt==n){
		cout<<n;
		return 0;
	}
	if(k==0&&cnt==0){
		cout<<n;
		return 0;
	}
	if(k==0&&cnt==n){
		cout<<n/2;
		return 0;
	}
	
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
