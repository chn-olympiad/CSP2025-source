#include<bits/stdc++.h>
using namespace std;
int n,l[5005],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&l[i]);
	if(l[1]+l[2]>l[3]&&l[1]+l[3]>l[2]&&l[3]+l[2]>l[1])cout<<1;
	else cout<<0;
	return 0;
}
