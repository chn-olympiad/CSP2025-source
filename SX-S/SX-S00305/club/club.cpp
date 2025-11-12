#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+1;
int t;
long long ref1;
long long jishu;
struct node{
	int a1,a2,a3;
}s[maxn];
struct node2{
	int ci;
}c[4];
int n;
long long num=INT_MIN;
void dfs(int st,long long ans){
	if(st==n+1){
		num=max(num,ans);
		return;
	}
	for(int i=1;i<=3;i++){
		if(c[i].ci<ref1){
			c[i].ci++;
			if(i==1) dfs(st+1,ans+s[st].a1);
			if(i==2) dfs(st+1,ans+s[st].a2);
			if(i==3) dfs(st+1,ans+s[st].a3);
			c[i].ci--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int time=1;time<=t;time++){
		
		jishu=0;
		num=INT_MIN;
		cin>>n;
		ref1=n>>1;
		for(int i=1;i<=n;i++){
			cin>>s[i].a1>>s[i].a2>>s[i].a3;
			if(s[i].a2==0) jishu++;
			if(s[i].a3==0) jishu++;
		}
		if(jishu==n*2) {
			jishu=0;
			long long y[maxn];
			for(int i=1;i<=n;i++){
				y[i]=s[i].a1;
			}
			sort(y+1,y+n+1);
			reverse(y+1,y+n+1);
			for(int j=1;j<=ref1;j++){
				jishu=jishu+y[j];
			}
			cout<<jishu<<endl;
			continue;
		}
		dfs(1,0);
		cout<<num<<endl;
	}
	return 0;
}
