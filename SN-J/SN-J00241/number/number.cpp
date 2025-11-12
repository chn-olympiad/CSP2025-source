#include <bits/stdc++.h>

using namespace std;

char s [1000001];
char a [1000001];
int m = 1;

int main () {
	freopen ("number.in", "r", stdin);
	freopen ("number.out","w", stdout);
    scanf ("%s", s+1);
    int l = strlen(s+1);
    for (int i = 1 ; i <= l; i++){
        if (s[i] <= '9' &&s[i] >= '0'){
            a [m] = s[i] ;
            m++;
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = i + 1 ; j <= m ; j++){
            if (a[i] < a[j])
                swap (a[i], a[j]);
        }
    }
    for (int i = 1 ; i <= m; i++) {
        printf ("%c", a[i]);
    }
    fclose (stdin); fclose (stdout);
    return 0;
}
