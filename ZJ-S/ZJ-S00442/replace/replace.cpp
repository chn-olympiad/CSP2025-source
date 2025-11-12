#include<bits/stdc++.h>
using namespace std;
int n,m,i,ans,j;
string s[500100][2],s1,s2;
int check(int t,int y){
	int i,j,lsx=s1.length(),lsy=s[y][0].length();
	for(i=t;i<=lsx-lsy+1;i++){
		int fl=0;
		for (j=t;j<=t+lsy-1;j++)
			if (s[y][0][j]!=s1[j]){
				fl=1;
				break;
			}
		if (!fl) return i;
	}
	return -1;
}
bool pd(int t,int x){
	string ss=s1;
	int i,ls=s[x][0].length();
	for (i=t;i<=t+ls-1;i++)
		ss[i]=s[x][1][i];
	if (ss==s2) return 1;
	return 0;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++)
		cin>>s[i][0],cin>>s[i][1];
	for (i=1;i<=m;i++){
		cin>>s1;cin>>s2;ans=0;
		for (j=1;j<=n;j++){
			int t=0;int w=check(t,j);
			while (w!=-1){
				if (pd(w,j)) ans++;
				w=check(w+1,j);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/