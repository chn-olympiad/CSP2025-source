#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,maxa = -1,j = 1;
	cin>>n>>k;
	int a[500005];
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		if(a[i] ^ a[j] == k) {
			maxa++;
		}
		j++;
	} 	
	cout<<maxa;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
