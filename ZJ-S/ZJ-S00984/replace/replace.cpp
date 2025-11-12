#include<iostream>
#include<string>
using namespace std;
int n, q, flag, ans;
string s2s[200005][2], str1, str2, str3;
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d %d", &n, &q);
	for(int i=0; i<n; i++){
		cin>>s2s[i][0]>>s2s[i][1];
	}for(int _=0; _<q; _++){
		cin>>str1>>str2;ans=0;
		for(int i=0; i<n; i++){
			for(int j=0; ;){
				str3=str1;
				flag=str1.find(s2s[i][0], j);
				if(flag==-1){
					break;
				}str3.replace(flag, s2s[i][1].size(), s2s[i][1]);
				if(str3==str2)ans++;
				j=flag+s2s[i][0].size()+1;
			}
		}printf("%d\n", ans);
	}
}