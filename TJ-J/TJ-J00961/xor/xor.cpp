#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,maxn=1,a[500005],t=0,tmp=0;
	memset(a,0,sizeof(a));
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		tmp^=a[i];
		if(tmp==k){
			t++;
			tmp=0;
			continue;
		}
	}
	cout<<t;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
