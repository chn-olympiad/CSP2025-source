#include<bits/stdc++.h>
using namespace std;
int n,k,x;
int a[500005],v[500005],ans[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>x;
		a[i]=a[i-1]^x;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((a[i-1]^a[j])==k){
				v[i]=j;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(v[i]==0)ans[i+1]=max(ans[i+1],ans[i]);
		if(v[i]!=0){
			ans[i]++;
			ans[v[i]+1]=max(ans[v[i]+1],max(ans[i],ans[i-1]));
		}
		ans[i]=max(ans[i],ans[i-1]);
	}
	cout<<ans[n];
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
