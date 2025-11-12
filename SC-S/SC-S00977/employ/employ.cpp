#include<bits/stdc++.h>
using namespace std;
int n,m,a[600],b[600],z;
void dfs(int p,int l,int c,int d,int e){
	if(c==n-1&&e>=m){
		z++;
		return;
	}
	if(a[p+1]==0) d++;
	if(b[p+1]>d) e++;
	for(int i=l+1;i<n;i++){
		dfs(i,l+1,c+1,d,e);
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	string s;
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		a[i]=s[i-1]-'0';
		cin>>b[i];
	}
	dfs(0,0,0,0,0);
	cout<<z;
	fclose(stdin);
	fclose(stdout);
	return 0;
}