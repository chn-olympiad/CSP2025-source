#include <bits/stdc++.h>
using namespace std;
int n,k,w=1;
int a[10001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			if(i==1 || i==n){
				cout<<w+1;
				return 0;
			}
		}
	}
	cout<<w;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
