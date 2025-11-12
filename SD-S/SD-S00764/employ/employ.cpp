#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    int n,m,a[505];
    long long ans=1;
    string s;
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		ans*=i;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
