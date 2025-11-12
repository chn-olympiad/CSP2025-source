#include<bits/stdc++.h>
using namespace std;
struct node{
	int l,r;
}mp[500005];
int n,k,cnt,ans;
int a[500005];
void d(int dp){
	int l=dp;
	while(l<=n){
		int r=l;
		while(r<=n){
			int o=a[l];
			for(int i=l+1;i<=r;i++)o=o^a[i];
			if(o==k){
				mp[++cnt]=(node){l,r};
				d(r+1);
				cnt--;
			}
			r++;
		}
		l++;
	}
	ans=max(ans,cnt);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	d(1);
	cout<<ans<<endl;
	return 0;
}