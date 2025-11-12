#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
const int N=2e5+10,M=2e6+10;
string s1[N],s2[N],t1,t2;
int n,q,ans,s[N];
bool f[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		s1[i]=" "+s1[i];
		s2[i]=" "+s2[i];
	}
	while(q--){
		cin>>t1>>t2;
		int len=t1.size(),cnt=0;
		ans=0;	
		if(len!=t2.size()){
			printf("0\n");
			continue;
		}
		t1=" "+t1;
		t2=" "+t2;
		for(int i=1;i<=len;i++){
			if(t1[i]==t2[i])f[i]=0;
			else f[i]=1;
			if(f[i]!=f[i-1])cnt++,s[cnt]=i;
		}
		if(cnt>2){
			printf("0\n");
			continue;
		}
		if(cnt==1)s[2]=n+1;
		for(int i=1;i<=n;i++){
			bool flag=1;
			string tmp2=t1;
			int lens=s1[i].size();
			for(int j=1;j<lens;j++){
				if(i+j-1>len){
					flag=0;
					continue;
				}
				tmp2[i+j-1]=s2[i][j];
				if(s1[i][j]!=t1[i+j-1]){
					flag=0;
					break;
				}
				if(s2[i][j]!=t2[i+j-1]){
					flag=0;
					break;
				}
			}
			if(tmp2!=t2)flag=0;
			if(flag)ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}

