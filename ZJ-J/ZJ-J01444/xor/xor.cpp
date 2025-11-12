#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,k,ans,s[500010],l[500010],f[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int a;scanf("%d",&a);
		s[i]=s[i-1]^a;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j>=1;j--){
			int a=s[i]^s[j-1];
			if(a==k){
				l[i]=j;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(l[i]){
			if(f[l[i]-1]+1>f[i-1]) f[i]=f[l[i]-1]+1;
			else f[i]=f[i-1];
		}else f[i]=f[i-1];
	}
	cout<<f[n];
	fclose(stdin);
	fclose(stdout);
	return 0;
}