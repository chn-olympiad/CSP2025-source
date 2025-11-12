#include<bits/stdc++.h>
#pragma GCC optimize(2,3,4,5,6,7,"Ofast")
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int n,a[5555],su;
void dfs(int pos,int s,int gs){
	if(pos>n)return;
	if(gs>=2&&s>a[pos]){
		su++;
	}
	dfs(pos+1,s+a[pos],gs+1);
	dfs(pos+1,s,gs);
}
int main(){
  freopen("polygon.in","r",stdin);freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(1,0,0);
	cout<<su;
	return 0;
}
/*
5
1 2 3 4 5

5
2 2 3 8 10

*/
