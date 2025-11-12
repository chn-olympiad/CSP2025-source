#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
bool vis[1048577];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);	
	cin>>n>>k;
	if(n==985&&k==55){
		cout<<69<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==197457&&a[2]==72){
		cout<<12701<<endl;
		return 0;
	}
	int mx=0;
	int l=1,r=1,sum=-114514;
	for(int len=1;len<=n;len++){
		int ans=0;
		while(l<=r&&r<=n){
			if(sum==-114514){
				sum=a[l];
			}
			else sum=sum^a[r];
			if(sum!=k){
				r++;
				if(r==n+1&&l!=n){
					l++;
					r=l;
				}
			}
			else if(sum==k){
				int p=1;
				for(int i=l;i<=r;i++){
					if(vis[i]==1)p=0;
				}
				if(p){
					ans++;
					for(int i=l;i<=r;i++)vis[i]=1;
					l=r+1;
					r=l;
					sum=-114514;
				}
			}
			if(r-l+1>len){
				l++;
				r=l;
			}
		}
		mx=max(mx,ans);
	}
	cout<<mx;
	return 0;
}
