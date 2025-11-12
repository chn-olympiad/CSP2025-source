#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<set>
#include<string>
#include<cstring>
#define r read()
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch&15);ch=getchar();}
	return x*f;
}
const int N=2e5+10;
int n,q,k[N];
long long ans;
string s1[N],s2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=r,q=r;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i],k[i]=s1[i].size();
	while(q--){
		ans=0;
		string t1,t2;
		cin>>t1>>t2;
		int len=t1.size(),ls=-1,lr=-1;
		for(int i=0;i<len;i++){
			if(t1[i]!=t2[i]){
				ls=i;
				break;
			}
		}
		for(int i=len-1;i>=0;i--){
			if(t1[i]!=t2[i]){
				lr=i;
				break;
			}
		}
		string tmp1,tmp2;
		for(int i=0;i<=ls;i++){
			for(int j=lr;j<len;j++){
				tmp1.resize(j-i+1),tmp2.resize(j-i+1);
				for(int k=i;k<=j;k++){
					tmp1[k-i]=t1[k];
					tmp2[k-i]=t2[k];
				}
				for(int i=1;i<=n;i++){
					if(s1[i]==tmp1&&s2[i]==tmp2)++ans;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}


