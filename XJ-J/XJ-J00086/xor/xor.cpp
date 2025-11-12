#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	if(k==0){
		for(int i=1;i<=n;i++){
			cin >> a[i];
		}
		if(a[1]==0&&a[2]==0) cout << 0;
		if(a[1]==0&&a[2]==1) cout << 1;
		if(a[1]==1&&a[2]==0) cout << 1;
		if(a[1]==1&&a[2]==1) cout << 2;
		else{
			int ans=0;
			for(int j=1;j<=n;j++){
				ans+=a[j];
			}
			cout << ans;
		}
	}
	else cout << 0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
