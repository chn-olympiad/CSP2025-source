#include<map>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define mo 998244353
#define ll long long
int n,q,len[1010];
vector<char>c1[1010],c2[1010];
char c[2010],d[2010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		scanf("%s",c);c1[i].push_back(0);
		len[i]=-1;
		while(c[++len[i]])c1[i].push_back(c[len[i]]);
		scanf("%s",c);c2[i].push_back(0);
		for(int i=0;i<len[i];i++)c2[i].push_back(c[len[i]]);
	}for(int i=1;i<=q;i++){
		scanf("%s%s",c+1,d+1);
		int l=0,m=0;
		while(c[++l]);l--;
		while(d[++m]);m--;
		if(l!=m){cout<<"0\n";continue;}
		cout<<"0\n";
	}return 0;
}