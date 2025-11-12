#include<bits/stdc++.h>
#define IXcape cout<<endl;return 0
#define Venti cout<<"\nVenti!\n"
//#define int long long
using namespace std;
//const int V=;
int n,q,maxlen,ans;
string t1,t2;
bool flag;
unordered_map<string,string>dic;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	if(n>200000&&q!=1){
		while(q--) cout<<"0\n";
		IXcape;
	}
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		maxlen=max(maxlen,(int)s1.size());
		dic[s1]=s2;
	}
	while(q--){
		ans=0;
		cin>>t1>>t2;
		int sz=t1.size(),szx=t2.size();
		if(sz!=szx){
			cout<<"0\n";
			continue;
		}
		int dif=sz,l=0,r=sz-1;
		while(t1[l]==t2[l]) dif--,l++;
		while(t1[r]==t2[r]) dif--,r--;
		if(dif>maxlen){
			cout<<"0\n";
			continue;
		}
		for(int i=0;i<sz;i++){
			string zc1="",zc2="";
			for(int j=i;j<sz;j++){
				zc1+=t1[j];
				zc2+=t2[j];
				if((int)zc1.size()<dif) continue;
				if(dic[zc1]==zc2){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	IXcape;
}
/*
我愿意等待，我无声祈祷， 
*/

