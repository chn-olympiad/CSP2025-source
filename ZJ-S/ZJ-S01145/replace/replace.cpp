#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int N=2e5+10;
int n,m;
string s[3][N],s1,s2;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>s[1][i]>>s[2][i];
	}
	while(m--){
		int cnt=0;
		cin>>s1>>s2;
		if(s1.size()!=s2.size()) cout<<cnt<<"\n";
		else{
			for (int i=0;i<s1.size();i++){
				for (int j=1;j<=n;j++){
					bool flag=true;
					if(i+s[1][j].size()>s1.size()){
						flag=false;
						continue;
					}
					for (int k=0;k<i;k++){
						if(s1[k]!=s2[k]) flag=false;
					}
					for (int k=i;k<i+s[1][j].size();k++){
						if(s1[k]!=s[1][j][k-i] || s2[k]!=s[2][j][k-i]) flag=false;
					}
					for (int k=i+s[1][j].size();k<s1.size();k++){
						if(s1[k]!=s2[k]) flag=false;
					}
					if(flag) cnt++;
				}
			}
			cout<<cnt<<"\n";
		}
	}
	return 0;
}