#include<bits/stdc++.h>
#define int long long
using namespace std;
int pre[500005],a[500005],n,k;
map<int,int> lst;
int rpos=0;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	pre[1]=a[1];
	for(int i=2;i<=n;i++){
		pre[i]=pre[i-1]^a[i];
	}
	int cnt=0;
	lst[0]=0;
	for(int i=1;i<=n;i++){
		if(lst.count(pre[i]^k)&&lst[pre[i]^k]>=rpos){
			cnt++;
			rpos=i;
		}
		lst[pre[i]]=i;
	}
	cout<<cnt<<"\n";
	return 0;
}