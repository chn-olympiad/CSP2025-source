#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 20;
struct node{
	string s1,s2;
	int l;
}s[N];
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i = 1;i <= n;i++){
		cin >> s[i].s1 >> s[i].s2;
		s[i].l = s[i].s1.size();
	}
	while(q--){
		int ans = 0;
		string s1,s2;
		cin >> s1 >> s2;
		int l1 = s1.size(),l2 = s2.size();
		if(l1 != l2){
			printf("0\n");
			continue;
		}
		for(int i = 1;i <= n;i++){
			if(s[i].l > l1)
				continue;
			for(int j = 0;j < l1 - s[i].l + 1;j++){
				string snew = s1.substr(j,s[i].l);
				if(snew != s[i].s1)
					continue;
				string s3 = s1.substr(0,j) + s[i].s2 + s1.substr(j+s[i].l,l1-j-s[i].l+1);
				if(s3 == s2)
					ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
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
