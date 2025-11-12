#include <bits/stdc++.h>
using namespace std;

int const N=500010;
int n,k,idx=1;
int a[N],s[N],lst[N];
int f[N];
unordered_map<int,int> mk;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
		
	scanf("%d %d",&n,&k);
	int t,p;
	mk[0]=1;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[i]=s[i-1]^a[i];
		t=s[i]^k;
		f[i]=f[i-1];
		if (mk.count(t)){
			p=lst[mk[t]];
			f[i]=max(f[i],f[p]+1);
		}
		if (!mk.count(s[i])) mk[s[i]]=++idx;
		lst[mk[s[i]]]=i;
	}
	printf("%d",f[n]);
	
	return 0;
} 
