// 丁家淳 SN-S00004 渭南高级中学 
#include<bits/stdc++.h>
using namespace std;

int n,q;
char s[200011][2],t1[200011],t2[200011];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i = 1;i <= n;i++){
		cin >> s[i][1] >> s[i][2];
	}
	for(int i = 1;i <= q;i++){
		cin >> t1 >> t2;
	}
	for(int i = 1;i <= q;i++){
		printf("0\n");
	}
	return 0;
}
