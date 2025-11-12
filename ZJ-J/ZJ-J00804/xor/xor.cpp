#include<bits/stdc++.h>
using namespace std;
int n,k,f[500010],ans;
map<int,int>m;
inline int rd(){
	int x=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	return x;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=rd();
	k=rd();
	for(int i=1;i<=n;i++){
		int x=rd();
		f[i]=(f[i-1]^x);
	}
	int o=1;
	m[0]=1;
	for(int i=1;i<=n;i++){
		int u=(k^f[i]);
		if(m[u]>=o){
			ans++,o=i+1;
			m.clear();
		}
		m[f[i]]=i+1;
	}
	cout<<ans;
	return 0;
}
