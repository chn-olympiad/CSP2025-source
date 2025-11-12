#include<bits/stdc++.h>
using namespace std;
int n,q,ans=0;
string s[2][200101],t[2][200101];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s%s",&s[0][i],&s[1][i]);
		//printf("%s %s\n",&s[0][i],&s[1][i]);
	}
	for(int i=1;i<=q;i++){
		ans=0;
		scanf("%s%s",&t[0][i],&t[1][i]);
		//printf("%s %s\n",&t[0][i],&t[1][i]);
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
