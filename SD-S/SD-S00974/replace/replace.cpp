#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 4e5+5;
const int M = 1e7+5;
int n,q;
int fail[M],cntf,cnts;
int k[N];
string s[N];
char c[M],c1[M];
void kmp(string ss,int kk){
	for(int i = 1;i <= kk;i++){
		c[i] = ss[i-1];
//		cout << c[i] << " ";
	}
		
		
	int j = 0;
	for(int i = 2;i <= kk;i++){
		while(j&&c[j+1] != c[i]) j = fail[j+cntf];
		if(c[j+1] == c[i]) j++;
		fail[i+cntf] = j;
	}
	cntf += kk+1;
}
int a[N],cnta;
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	freopen("replace.in","r",stdin);
//	freopen("replace.out","w",stdout);
//	cout << sizeof(s1)/1e6;
	cin >> n >> q;
	for(int i = 1;i <= n;i++){
		cin >> s[++cnts];
		k[cnts] = s[cnts].size();
		kmp(s[cnts],k[cnts]);
		cin >> s[++cnts];
		k[cnts] = s[cnts].size();
		kmp(s[cnts],k[cnts]);
	}
	
	
	while(q--){
		cin >> (c1+1);
		cntf = 0;
		int kk = strlen(c1);
		cout << kk << " ";
//		for(int k = 1;k <= n;k++){
//			int p1 = i*2;
//			int p2 = p1-1;
//			for(int i = 1;i <= kk;i++){
//				c[i] = s[p1][i-1];
//			int j = 0;
//			for(int i = 1;i <= kk;i++){
//				while(j&&c[j+1] != c1[i]) j = fail[j+cntf];
//				if(c[j+1] == c1[i]) j++;
//				if(j == )
//			}
//			cntf += kk+1;
//		}
	}
//	for(int i = 0;i < cntf;i++) cout << fail[i] << " ";
	return 0;
//	fclose(stdin);
//	fclose(stdout);
}

