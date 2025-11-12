#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937 mrand(1);
const int N = 210000,M= 1200000;
string s,t;
map<string,string> mp;
int n,m,ss[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++){
		cin >> s >> t;
		mp[s] = t;
		mp[t] = s;
	}for(int l = 1;l <= m;l++){
		cin >> s >> t;
		int x = s.length(),ans = -1,len = 0;
		string la = "",ls = "";
		for(int j = 0;j < x;j++){
			if(s[j] != t[j]){
				ss[len++] = j;
				la += s[j];
				ls += t[j];
			}if(!len){
				la += s[j];
				ls += t[j];
			}
		}for(int i = 1;i < len;i++){
			if(ss[i] != ss[i-1]+1){
				ans = 0;
			}
		}if(!ans){
			printf("0");
			if(l != m){
				puts("");
			}continue;
		}for(int j = 0;j <= ss[0];j++){
			for(int k = ss[len-1]+1;k <= x;k++){
				if(mp[la] == ls){
					ans++;
				}//cout << la << ' ' << ls << endl;
				la += s[k];
				ls += t[k];
			}la = ls = "";
			for(int k = j+1;k <= ss[len-1];k++){
				la += s[k];
				ls += t[k];
			}
			
		}printf("%d",ans+1);
		if(l != m){
			puts("");
		}
	}
    
    return 0;
}
