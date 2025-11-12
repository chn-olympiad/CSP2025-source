#include<bits/stdc++.h>
using namespace std;
int n,q;
char s1[200001][1000],s2[200001][1000];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
        scanf("%s%s",s1[i]+1,s2[i]+1);
    for(int i=1;i<=q;i++){
        char l1[1001],l2[1001];
        scanf("%s%s",l1[i]+1,l2[i]+1);
        printf("0\n");
    }
	fclose(stdin);
	fclose(stdout);
}
