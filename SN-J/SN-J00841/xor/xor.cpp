#include<bits/stdc++.h>
using namespace std;
int n,k;
int cnt;
int a[265];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		
	}
	for(int i=1;i<n;i++){
		if(a[i]<k)
		cnt++;
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
return 0;
}
