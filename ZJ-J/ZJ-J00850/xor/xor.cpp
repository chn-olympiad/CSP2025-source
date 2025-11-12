#include<bits/stdc++.h>
using namespace std;
const int MAXN=114514*5;
int lst[MAXN],n,k,now,lsp,ans;
map<int,int> m;
signed main(){
	freopen("xor.in","r+",stdin);
	freopen("xor.ans","w+",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>lst[i];
	}
	for(int i=1;i<=n;i++){
		now^=lst[i];
		if(m[now^k]>=lsp){
			if(ans==0&&m[now^k]==0&&now!=k){
				m[now]=i;
				continue;
			}
			lsp=i;
			ans++;
		}
		m[now]=i;
	}
	cout<<ans;
}
