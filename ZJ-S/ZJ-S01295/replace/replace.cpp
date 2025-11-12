#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N = 2e5+10,L = 5e6+10;
int n,q;
string s[N][3];
ull p[L],hashs[N][3],hasht1[L],hasht2[L];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> q;
	for(int i = 1;i <= L-10;i ++){
		p[i]=p[i-1]*13331;
	}
	for(int i = 1;i <= n;i ++){
		cin >> s[i][1] >> s[i][2];
		s[i][1]=" "+s[i][1],s[i][2]=" "+s[i][2];
		hashs[i][1]=hashs[i][2]=1;
		for(int j = 1;j < s[i][1].size();j ++){
			hashs[i][1]=hashs[i][1]*13331+s[i][1][j]-'a'+1;
		}
		for(int j = 1;j < s[i][2].size();j ++){
			hashs[i][2]=hashs[i][2]*13331+s[i][2][j]-'a'+1;
		}
	}
	while(q--){
		string t1,t2;
		int ans=0;
		cin >> t1 >> t2;
		t1=" "+t1;
		t2=" "+t2;
		if(t1.size()!=t2.size()){
			cout << "0\n";
			continue;
		}
		ull hasht1=1,hasht2=1;
		for(int i = 1;i < t1.size();i ++){
			hasht1=hasht1*13331+t1[i]-'a'+1;
		}
		for(int i = 1;i < t2.size();i ++){
			hasht2=hasht2*13331+t2[i]-'a'+1;
		}
		for(int i = 1;i <= n;i ++){
			if(s[i][1].size()>t1.size()){
				continue;
			}
			//zichuan:s[i][1] pipei:t1
			int kmp[s[i][1].size()];
			memset(kmp,0,sizeof kmp);
			int j=0;
			for(int k = 1;k < s[i][1].size();k ++){
				while(j && s[i][1][k]!=s[i][1][j])	j=kmp[j];
				if(s[i][1][k]==s[i][1][j])	j++;
				kmp[k]=j;
//				cout << kmp[k] << " ";
			}
//			cout << "\n";
			j=0;
			int st=INT_MAX,ed=INT_MAX;
			for(int k = 1;k < t1.size();k ++){
				while(j && t1[k]!=s[i][1][j])	j=kmp[j];
				if(t1[k]==s[i][1][j])	j++;
				if(j==s[i][1].size()){
					st=j-s[i][1].size()+2,ed=j;
					j=kmp[j];
					if(hasht1-hashs[i][1]*p[st-1]+hashs[i][2]*p[st-1]==hasht2){
						ans++;
						break;
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}