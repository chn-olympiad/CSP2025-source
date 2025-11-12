#include<bits/stdc++.h>
#define int long long
using namespace std;
string s1[200005],s2[200005];
vector<int> pi[2][200005];
int n,q;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		bool f=0;
		string difa="",difb="";
		if(t1.size()!=t2.size()){
			cout<<0<<"\n";
			continue;
		}
		int cnt=0;
		for(int i=0;i<n;i++){
			pi[0][i].clear();
			pi[1][i].clear();
			pi[0][i].push_back(0);
			int n1=s1[i].size(),n2=s2[i].size();
			string k1=s1[i]+'#'+t1,k2=s2[i]+'#'+t2;
			for(int j=1;j<k1.size();j++){
				int x=pi[0][i][j-1];
				while(x!=0&&k1[j]!=k1[x]){
					x=pi[0][i][x-1];
				}
				if(k1[j]==k1[x]) x++;
				pi[0][i].push_back(x);
			}
			pi[1][i].push_back(0);
			for(int j=1;j<k2.size();j++){
				int x=pi[1][i][j-1];
				while(x!=0&&k2[j]!=k2[x]){
					x=pi[1][i][x-1];
				}
				if(k2[j]==k2[x]) x++;
				pi[1][i].push_back(x);
			}
			bool f=1;
			int ct=0;
			for(int j=0;j<k1.size();j++){
				if(pi[0][i][j]==n1&&pi[1][i][j]!=n2) f=0;
				if(pi[0][i][j]!=n1&&pi[1][i][j]==n2) f=0;
				if(pi[0][i][j]==n1&&pi[1][i][j]==n2) ct++;
			}
			if(f&&ct==1) cnt++;
		}
		cout<<cnt<<"\n";
	}
	return 0;
}//25pts(maybe will more high)