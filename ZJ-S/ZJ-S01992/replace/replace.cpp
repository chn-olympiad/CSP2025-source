#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,Q;
string s1[N],s2[N];
bool check(string x,string y,int t){
	int len=s1[t].size();
	for(int i=0;i+len-1<x.size();i++){
		bool flag=true;
		for(int j=0;j<len;j++)
			if(x[i+j]!=s1[t][j]){
				flag=false;
				break;
			}
		if(!flag) continue;
		string z=x;
		for(int j=0;j<len;j++) z[i+j]=s2[t][j];
		if(z==y) return true;
	}
	return false;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&Q);
	for(int i=1;i<=n;i++)
		cin>>s1[i]>>s2[i];
	while(Q--){
		string x,y; cin>>x>>y;
		int cnt=0;
		for(int i=1;i<=n;i++)
			cnt+=check(x,y,i);
		printf("%d\n",cnt); 
	}
	return 0;
}
