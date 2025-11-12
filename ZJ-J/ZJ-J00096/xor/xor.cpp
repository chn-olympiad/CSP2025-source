#include<bits/stdc++.h>
using namespace std;
long long n,sb,a[50005],ans,f,vis[50005],flag;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>sb;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			f=0;
			flag=0;
			for(int k=j;k<=i;k++){
				if(vis[k]==1){
					flag=1;
					break;
				}
				f^=a[k];
			}
			if(f==sb&&flag==0){
				ans++;
				for(int k=j;k<=i;k++){
					vis[k]=1;
				}
			}
			
		}
		
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
