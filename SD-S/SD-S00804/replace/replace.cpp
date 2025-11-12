#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N=1e6+10,MOD=1e9+7;
int n,q;
string s1[N],s2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	while(q--){
		int ans=0;
		string t1,t2;
		cin>>t1>>t2;
		for(int i=1;i<=n;i++){
			int len=s1[i].size();
			for(int j=0;j+len<=t1.size();j++){
				string tmp=t1,tmp1="";
				for(int k=j;k<j+len;k++) tmp1.push_back(t1[k]);
				if(tmp1==s1[i]) tmp.replace(j,len,s2[i]);
				if(tmp==t2) ans++;
			} 
		}
		cout<<ans<<endl;
	}
	return 0;
}

