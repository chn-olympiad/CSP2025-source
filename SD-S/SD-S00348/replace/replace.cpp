#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N = 100+3;
string dc[N][2];
int len[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,q;
	cin>>n>>q;
	for (int i = 1;i <= n;i++){
		cin>>dc[i][0]>>dc[i][1];
		len[i] = dc[i][0].size();
	}
	string s1,s2;
	int ans;
	while (q--){
		ans = 0;
		cin>>s1>>s2;
		int l = s1.size();
		if (l != s2.size()){
			cout<<0<<'\n';
			continue;
		}
		for (int i = 0;i < l;i++){
			for (int j = 1;j <= n;j++){
				if (len[j] > l-i)  continue;
				if (s1.substr(i,len[j]) == dc[j][0]){
					for (int k = 0;k < len[j];k++){
						char t = s1[i+k];
						s1[i+k] = dc[j][1][k];
						dc[j][1][k] = t;
					}
					if (s1 == s2)  ans++;
					for (int k = 0;k < len[j];k++){
						char t = s1[i+k];
						s1[i+k] = dc[j][1][k];
						dc[j][1][k] = t;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}
