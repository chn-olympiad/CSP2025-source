#include <bits/stdc++.h>
using namespace std;
const int N=200005;
int n,Q,l1,l2;
map<int,vector<int> > bb;
string s[N][2];
bool checkB(string t1,string t2){
	for(int i=0;i<l1;i++)
		if(t1[i]!='a'&&t1[i]!='b') return 0;
	for(int i=0;i<l2;i++)
		if(t2[i]!='a'&&t2[i]!='b') return 0;
	return 1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>Q;
	int B=1;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		if(!checkB(s[i][0],s[i][1])) B=0;
		else{
			int x1=s[i][1].find('b'),x2=s[i][0].find('b');
			bb[x1-x2].push_back(i);
		}
	}
	while(Q--){
		string t1,t2;
		cin>>t1>>t2;
		l1=t1.length(),l2=t2.length();
		if(l1-l2){ cout<<"0\n"; continue; }
		if(!checkB(t1,t2)&&B==1){ cout<<"0\n"; continue; }
		else if(B==1){
			int x1=t2.find('b'),x2=t1.find('b'),ans=0;
			for(auto i:bb[x1-x2]){
				if(s[i][0].find('b')<=x2&&s[i][0].size()<=l1) ++ans;
			}
			cout<<ans<<'\n';
			continue;
		}
	}
	return 0;
}
