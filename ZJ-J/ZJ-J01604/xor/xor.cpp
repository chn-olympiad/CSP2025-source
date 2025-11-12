#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],sum,j,ans,vis[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k==0){
		for(int i=0;i<n;i++){
			cin>>a[i];
			if(a[i]==k){
				sum++;
				vis[i]=1;
			}
		}
		for(int i=1;i<n;i++){
			if(a[i]==a[i-1]&&vis[i-1]==0&&vis[i]==0){
				sum++;
				vis[i]=1;
				vis[i-1]=1;
			}
		}
	}else{
		for(int i=0;i<n;i++){
			cin>>a[i];
			if(a[i]==k){
				sum++;
			}
		}
		for(int i=0;i<sum+1;i++){
			while(a[j]!=k&&j<n){
				ans=ans^a[j];
				if(ans==k){
					ans=0;
					sum++;
				}
				j++;
			}
			j+=1;
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}