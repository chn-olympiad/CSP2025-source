#include <bits/stdc++.h>
using namespace std;
int a[500010],s[500010],t[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int i;
	for(i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
		t[i]=-1;
	}
	int j;
	for(i=1;i<=n;i++){
		for(j=i;j>0;j--){
			//[j,i]
			if(+(s[j-1]^s[i])==k){
				t[i]=j;
				//printf("[%d,%d]=%d^%d=%d,k=%d\n",j,i,s[j-1],s[i],s[j-1]^s[i],k);
				break;
			}
		}
	}
	int r=-1,ans=0;
	for(i=1;i<=n;i++){
		if(t[i]>r){
			r=i;
			ans++;
			//printf("s[%d,%d]=%d^%d\n",t[i],i,s[t[i]-1],s[i]);
		}
	}
	cout<<ans;
	return 0;
}