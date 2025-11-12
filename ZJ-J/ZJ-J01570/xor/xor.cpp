#include<bits/stdc++.h>
#define long long int
using namespace std;
const int maxn=1e6+5;
int n,k;
int a[maxn];
int dfs(int st,int cnt){
	for(int i=st;i<=n;i++){
		int xors=0;
		for(int j=i;j<=n;j++){
			xors=xors^a[j];
			if(xors==k){
				//cout<<"i:"<<i<<"j:"<<j<<"cnt:"<<cnt<<endl;
				return dfs(j+1,cnt+1);
			}
		}
	}
	return cnt;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	printf("%lld\n",dfs(1,0));
	return 0;
}