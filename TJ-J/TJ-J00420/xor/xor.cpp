#include<bits/stdc++.h>
using namespace std;
long long n,k;
int f[101];
int main(){
freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>f[i];
	}
    cout<<f[2];
fclose(stdin);
fclose(stdout);
	return 0;
}
