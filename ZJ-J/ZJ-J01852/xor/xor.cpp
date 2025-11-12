#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
bool vis[500005];
int ans;

bool judge(int l,int r){
	int sum=0;
	for(int i=l;i<=r;i++){
		if(vis[i]){
			return false;
		}
		sum=sum xor a[i];
	}
	if(sum!=k) return false;
	return true;
}

void dfs(){
	for(int i=0;i<n;i++){
		for(int j=1;j<n-i;j++){
			if(judge(i,i+j)){
				ans++;
				for(int k=i;k<=i+j;k++){
					vis[k]=1;
				}
			}
		}
	}
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==k){
			vis[i]=1;
			ans++;	
		}
	}
	dfs();
	cout<<ans;
	return 0;
}
