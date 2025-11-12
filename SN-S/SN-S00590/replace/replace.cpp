#include <bits/stdc++.h>
const int N=2e5+10;
using namespace std;
int n,q;
string str1[N],str2[N],ts1[N],ts2[N];
int main(){
	freopen("replace.in", "r",stdin);
	freopen("replace.out", "w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s%s",&str1[i],&str2[i]);
	}
	for(int i=1;i<=q;i++){
		scanf("%s%s",&ts1[i],&ts2[i]);
	}
	int cnt=0;
	for(int i=1;i<=q;i++){
		printf("%d\n",cnt);
	}
	return 0;
} 
