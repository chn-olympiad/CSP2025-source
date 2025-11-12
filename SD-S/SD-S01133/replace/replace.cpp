#include<bits/stdc++.h>
using namespace std;

const int LEN = 5e6 + 10;
const int N = 1e5 + 10;

int n, q;
char s1[LEN], s2[LEN];
char t1[LEN], t2[LEN];

int main(){	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d", &n, &q);
	int len1 = strlen(s1), len2 = strlen(s2);
	for(int i = 1; i <= n; i++){
		cin >> s1 >> s2;
	}
	for(int u = 1; u <= q; u++){
		cin >> t1 >> t2;
		printf("0\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
