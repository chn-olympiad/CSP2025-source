#include<bits/stdc++.h>
using namespace std;
map<string,string> rp;
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i = 1;i <= n;i++){
		string s1,s2;
		cin>>s1>>s2;
		rp[s1] = s2;
	}
	while(q--){
		int ans = 0;
		string s1,s2;
		cin>>s1>>s2;
		int LQ = 0,LH = 0;
		for(int i = 0;s1[i] == s2[i]&&i < (int)s1.size();i++) LQ++;
		for(int i = s1.size() - 1;s1[i] == s2[i]&&i >= 0;i--) LH++;
		for(int i = -1;i < LQ;i++){
			for(int j = s1.size();j >= (int)s1.size() - LH&&j > LQ - 1;j--){
				string tmp1="",tmp2="";
				for(int k = i + 1;k < j;k++){
					tmp1 += s1[k],tmp2 += s2[k];
				}
				if(rp[tmp1] == tmp2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}