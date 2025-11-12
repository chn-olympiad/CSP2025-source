#include<bits/stdc++.h>
using namespace std;
int n,m,c[1000005],w,ans,sum;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	for(int k=1;k<=n;k++){
		for(int j=1;j<=n;j++){
			swap(c[k],c[j]);
			ans=0;w=0;
			for(int i=1;i<=n;i++){
				if(!s[i-1] || w>=s[i]){
					w++;
				}else{
					ans++;
				}
			}
			if(ans==m) sum=(sum+1)%998244353;
		}
	}
	cout<<sum;
	return 0;
	fclose(stdin);
	fclose(stdout);
}

