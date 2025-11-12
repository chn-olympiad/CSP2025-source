#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+1;
string s[maxn][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		int id1,id2;
		for(int i=0;i<s1.size();i++){
			if(s1[i]=='b')id1=i;
		}
		for(int i=0;i<s2.size();i++){
			if(s2[i]=='b')id2=i;
		}
		int did=id2-id1-1;
	}
	return 0;
}

