#include <bits/stdc++.h>
using namespace std;
int a[500005],b[500005],c[1100050];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);freopen("xor.out","w",stdout);
	int n,k;cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)b[i]=b[i-1]^a[i];
	for(int i=1;i<1100040;i++)c[i]=-1;
	c[0]=0;
	int ans=0,lst=0;
	for(int i=1;i<=n;i++){
		int nd=k^b[i];
		//cout<<nd<<endl;
		if(c[nd]>=lst){
			ans++,lst=i;//cout<<"!"<<i<<" ";
		}
		c[b[i]]=i;
	}
	cout<<ans;
	return 0;
}
/*
4 2
2 1 0 3
*/