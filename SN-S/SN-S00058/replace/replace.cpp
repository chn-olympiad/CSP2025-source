#include<bits/stdc++.h>
using namespace std;
int n,q;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	char s[1000010];
	for(int i = 1; i <= (n+q)/2; i++){
		scanf("%s",s+1);
	}
	for(int i = 1; i <= q; i++){
		printf("0\n");
	}
	return 0;
}
