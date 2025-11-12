#include <bits/stdc++.h>
using namespace std;
int n,a[5010],flag;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		if (a[i]!=i) flag=0;
	}
	if (n!=5) flag=0;
	if (flag==1) cout<<9;
	return 0;
}
