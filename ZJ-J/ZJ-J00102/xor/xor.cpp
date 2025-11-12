#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=1050000;
int n,k,c[N],a[N],s[N];
vector<int> v[M];
void dfs(int p){
	if(p>n) return;
	if(a[p]==k&&p!=0) s[p]++;
	if(s[p]>s[p+1]){
		s[p+1]=s[p];
		dfs(p+1);
	}
	int f=c[p]^k;
	for(int i=0;i<v[f].size();i++){
		if(v[f][i]>p&&s[p]+1>s[v[f][i]+1]){
			s[v[f][i]+1]=s[p]+1;
			dfs(v[f][i]+1);
			return;
		}
	}
	
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(s,-1,sizeof s);
	s[0]=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		c[i]=c[i-1]^a[i];
	}
	for(int i=0;i<=n;i++){
		v[c[i]].push_back(i);
	}
	dfs(0);
	printf("%d",s[n+1]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
