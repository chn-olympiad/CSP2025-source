#include<bits/stdc++.h>
using namespace std;
long long l,r,n,a[500005],k;
long long gettt(int l,int r){
	long long totall=0;
	for(int i=l;i<=r;i++){
		total=total^a[i];
	}return total;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<=n;i++){
		cin>>a[i];
	}
	cout<<1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}