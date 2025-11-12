#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	int ret=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		if(x==k) ret++;
	}
	cout<<ret;
	return 0;
}
