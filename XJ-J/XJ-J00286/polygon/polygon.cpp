#include <bits/stdc++.h>
using namespace std;
int n,a;
int ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
	}
	int cnt;
	for(int i=1;i<=n;i++){
		if(a!=0){
			ans++;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<ans;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
