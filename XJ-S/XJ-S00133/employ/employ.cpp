#include <bits/stdc++.h>
using namespace std;
int d[100010];
int diff[100010];
int n;
int ans=0;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			ans++;
		}
	} 
	for(int i=1;i<=n;i++){
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
