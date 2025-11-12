//50pts
#include<bits/stdc++.h>
using namespace std;
int n , T;
char a[5000050] , b[5000050] , c[5000050] , d[5000050];
int flaga = 0 , flagb = 0 , flagc = 0 , flagd = 0 , la , lb , maxl = 0;
int l[400040];
bool flag = 1;
vector< pair<char , char> > s[500020];
int main(){
	freopen("replace.in" , "r" , stdin);
	freopen("replace.out" , "w" , stdout);
	cin >> n >> T;
	for(int i = 1 ; i <= n ; i++){
		scanf("%s %s" , a , b);
		int len = strlen(a);
		maxl = max(maxl , len);
		for(int j = 0 ; j < len ; j++){
			s[i].push_back({a[j] , b[j]});
			if(a[j] == 'b') flaga++ , la = j;
			else if(a[j] != 'a') flag = 0;
			if(b[j] == 'b') flagb++ , lb = j;
			else if(b[j] != 'a') flag = 0;
		}
		l[200000 + la - lb]++;
	}
	while(T--){
		flagc = 0 , flagd = 0;
		scanf("%s %s" , c , d);
		int lenc = strlen(c) , lend = strlen(d);
		if(lenc != lend){
			printf("0\n");
			continue;
		}
		int lc = 0 , ld = 0;
		for(int i = 0 ; i < lenc ; i++){
			if(c[i] == 'b'){
				flagc++;
				if(lc == 0) lc = i;
			}
			else if(c[i] != 'a') flag = 0;
			if(d[i] == 'b'){
				flagd++;
				if(ld == 0) ld = i;
			}
			else if(d[i] != 'a') flag = 0;
		}
		if(flaga != 1 || flagb != 1 || flagc != 1 || flagd != 1) flag = 0;
		if(flag == 1){
			printf("%d\n" , l[200000 + lc - ld]);
			continue;
		}
	}
	return 0;
}

