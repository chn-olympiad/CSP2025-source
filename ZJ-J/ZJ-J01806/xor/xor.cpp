#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,k,a[500010],vis[500010],sum,ans,f;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k) sum++,vis[i]=1;
	}
	if(k==0||k==1){
		int f=0;
		for(int i=1;i<=n;i++){
			if(a[i]!=1){
				if(a[i]==0&&f!=2) f=1;
				else f=2;
			}
		}
		if(f==0) cout<<n/2;
		if(f==1){
			int cnt=0;
			if(k==0){
				for(int i=1;i<=n;i++){
					if(a[i]==0) cnt++;
					if(a[i]==1&&a[i+1]==1&&vis[i+1]==0&&vis[i]==0) cnt++,vis[i+1]=1;
				}
				cout<<cnt;
			}
			else{
				for(int i=1;i<=n;i++){
					if(a[i]==1) cnt++;
				}
				cout<<cnt;
			}
		}
	}
	else{
		for(int i=1;i<n;i++){
			int x=i;
			if(vis[x]==0){
				ans=a[x];
				while(vis[x+1]==0&&ans!=k){
					ans^=a[x+1];
					x++;
				}
				if(ans==k){
					sum++;
					for(int j=i;i<x;j++) vis[x]=1;
				}
			}
		}
		cout<<sum;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
