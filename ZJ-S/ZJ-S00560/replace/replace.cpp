#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(x,y,z) for(int x=y;x<=z;x++)
const int N=2e5+7,base=1237,mod=1e13+7;
int n,q;
unordered_map<int,int> mp;
map<pair<int,int>,int> mp2;
/*
5 2
xabcd xbcde
aafdd fdssf
aafdd fdssf
dsfs fsds
sdf sfdds
aafdd fdssf
aafdd fdssf
*/
int hsh(string s){
	int len=s.size();
	int res=0;
	for(int i=0;i<len;i++) res=(res*base+s[i])%mod;
	return res;
}
string s1,s2;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		mp[hsh(s1)]=hsh(s2);
//		cout<<hsh(s1)<<" "<<hsh(s2)<<"\n";
		mp2[{hsh(s1),hsh(s2)}]++;
	}
	rep(i,1,q){
		int ans=0;
		cin>>s1>>s2;
		int len=s1.size();
		int diffl=n,diffr=-1;
		rep(i,0,len-1){
			if(s1[i]!=s2[i]) diffl=min(i,diffl),diffr=max(i,diffr);
		}
//		cout<<len<<"\n";
		for(int i=0;i<len;i++){
			if(diffl<i) continue;
			int tmp1=0,tmp2=0;
			for(int j=i;j<len;j++){
				tmp1=(tmp1*base+s1[j])%mod;
				tmp2=(tmp2*base+s2[j])%mod;
//				cout<<i<<" "<<j<<" "<<tmp1<<" "<<tmp2<<"\n";
//				cout<<"diffr="<<diffr<<"\n";
				if(j<diffr) continue;
//				cout<<"!!"<<"\n";
				if(mp[tmp1]==tmp2){
//					cout<<"!!"<<"\n"
					ans+=mp2[{tmp1,tmp2}];
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
