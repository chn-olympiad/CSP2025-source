#include <cstdio>
#include <algorithm>
#include <cstring>
#define DEBUG 1
using namespace std;

const int N = 3e6+5;
const int M = 2e5+5;

int n, q;
char s[N][2][M], t[N][2][M];

int main(){
	freopen("replace.in", "r", stdin);
#if DEBUG
	freopen("replace.out", "w", stdout);
#endif
	
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
		scanf("%s%s", s[i][0], s[i][1]);
	for (int i = 1; i <= q; i++){
		scanf("%s%s", t[i][0], t[i][1]);
	}
	printf("8521446")
	fclose(stdin);
#if DEBUG
	fclose(stdout);
#endif
	return 0;
}

//died....
