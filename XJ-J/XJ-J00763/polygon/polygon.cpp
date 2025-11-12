#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	int a[5005];
	cin>>n;
	for(int i;i<=n;i++){
		cin>>a[i];
	}
	if(n=3){
		int h,g;
		h=a[1]+a[2]+a[3];
		g=2*max(max(a[1],a[2]),a[3]);
		if(h>g){
			cout<<1;
			return 0;
		}
		cout<<0;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
