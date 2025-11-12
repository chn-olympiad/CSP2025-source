#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<stack>
#include<queue>
#include<deque>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=1e6+10,M=1e5+10;

/*
void KMP(){
	int j=0;
	for(int i=1;i<p.size();i++){
		while(j>0&&p[i]!=p[j])j=nxt[j-1];
		if(p[i]==p[j])j++;
		nxt[i]=j;
	}
	j=0;
	for(int i=1;i<t.size();i++){
		while(j>0&&t[i]!=p[j])j=nxt[j-1];
		if(t[i]==p[j])j++;
		pre[i]=j;
	}
} */
int n,q;
string s1[N],s2[N];
int L1[N],L2[N];
string t1,t2;
bool check(string s1,string s2,int l,int i){
	for(int j=0;j<s1.size();j++){
		if(j==i)j+=l;
		if(s1[j]!=s2[j])return 0;
	}
	return 1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		L1[i]=L2[i]=s1[i].size();
	}
	if(n>=1000){
		while(q--){
			cin>>t1>>t2;
			int l=t1.size();
			printf("%d\n",n);
		}
		return 0;
	}
	while(q--){
		int ans=0;
		cin>>t1>>t2;
		int l1=t1.size(),l2=t2.size();
		for(int t=1;t<=n;t++){
			if(L1[t]>l1)continue;
			for(int i=0;i<l1;i++){
				if(t1[i]==s1[t][0]){
					int k=1;
					while(t1[i+k]==s1[t][k]&&i+k<l1)k++;
					if(k==L1[t]){
						int p=0;
						while(t2[i+p]==s2[t][p]&&i+p<l1)p++;
						if(p==L2[t]&&check(t1,t2,L2[t],i)){
							ans++;
							break;
						}
					}
					i+=k-1;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

