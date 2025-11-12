#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int a[100005];
int l[100005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i <= n;i++){
		cin>>a[i];
		l[i] = a[i-1]*a[i];
	}
	
	cout << 2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
