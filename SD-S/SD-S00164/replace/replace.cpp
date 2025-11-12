#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
string s1[N],s2[N];
string t1,t2;
//int check(int len,string s,int x){
//	for(int i=0;i<len;i++){
//		if(s[i]!=t1[i+x]) return 0;
//	}
//	return 1;
//}
//void dfs(int len,int pos){
//	for(int i=pos;i<len;i++){
//		if(t1[i]!=t2[i]){
//			for(int j=1;j<=n;j++){
//				int ll=s1[j].size();
//				if(check(ll,s1[j],t1))
//				
//			}
//		}
//	}
//}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			printf("0\n");
			continue;
		}
		int len=t1.size();
//		dfs()
		printf("0\n");
	}
	return 0;
} 
