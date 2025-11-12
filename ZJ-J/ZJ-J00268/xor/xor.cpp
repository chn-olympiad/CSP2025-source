#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,s[N];
int l,ans;
map<int,int>m;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&s[i]);
		s[i]^=s[i-1];
	}
	m[0]=1;
	for(int i=1;i<=n;i++){
		if(m[s[i]^k]){
			ans++;
			m.clear();
		}
		m[s[i]]=1;
	}
	cout<<ans<<endl;
	return 0;
}
