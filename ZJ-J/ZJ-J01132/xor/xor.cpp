#include<bits/stdc++.h>
using namespace std;
int a[1005],s[1005][1005],ans,maxn;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		s[i][i]=a[i];
	}
	if(maxn==1){
		if(k==1){
			for(int i=1;i<=n;i++)if(a[i]==1)ans++;
		}else{
			for(int i=1;i<=n;i++){
				if(a[i]==0||(a[i]==1&&a[i-1]==1))ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			s[i][j]=s[i][j-1]^a[j];
		}
	}
	int i,j,x=1;;
	for(j=1;j<=n;j++){
		for(i=x;i<=j;i++){
			if(s[i][j]==k){
				ans++;
				x=j+1;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}