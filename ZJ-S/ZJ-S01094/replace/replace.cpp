#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s[3];
string t[3];
int ccf2,ccf1,ss1,ss2;
map<int,int> mp;
int n,nm,q;
bool f;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[1]>>s[2];
		int nm=s[1].size();
		for(int j=0;j<nm;j++){
			if(s[1][j]=='b'){
				ss1=j;
			}
			if(s[2][j]=='b'){
				ss2=j;
			}
		}
		int mx=max(ss1,ss2);
		int mi=min(ss2,ss1);
		mp[ss1-ss2]++;
	}
	while(q--){
		cin>>t[1]>>t[2];
		int nm=t[1].size();
		for(int i=0;i<nm;i++){
			if(t[1][i]=='b'){
				ccf1=i;
			}
			if(t[2][i]=='b'){
				ccf2=i;
			}
		}
		cout<<mp[ccf1-ccf2]<<"\n";
	}
	return 0;
}
//×öµÄ
//3000+
