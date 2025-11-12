#include<bits/stdc++.h>
using namespace std;
int s=0;
int n,m;
int b[60],a[60];
char c[60];
bool back(){
	int fs=0;
	for(int i=1;i<=n;i++)
		if(fs>=a[b[i]]||c[i]=='0')
			fs++;
	if(n-fs>=m)return 1;
	else return 0;
}
void dfs(int k){
	if(k==n+1){
		if(back())s++;
		return;
	}
	for(int i=1;i<=n;i++){
		bool p=0;
		for(int j=1;j<k;j++){
			if(b[j]==i){
				p=1;
				break;
			}
		}
		if(p==0){
			b[k]=i;
			dfs(k+1);
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>c[i];
	for(int i=1;i<=n;i++)
	cin>>a[i];
	dfs(1);
	cout<<s;
	return 0;
}