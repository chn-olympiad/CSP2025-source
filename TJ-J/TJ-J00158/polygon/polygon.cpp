#include <bits/stdc++.h>
using namespace std;
int n,a[5005],m=-1,s=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		m=max(a[i],m);
		s+=a[i];
	}
	if(s>m*2) cout<<1;
	else cout<<0;
	fclose(stdin);
	fclose(stdout);
    return 0;
}
