#include<bits/stdc++.h>
#define int long long
#define uint unsigned long long
using namespace std;
const int N=2e6+5;
int n,q,ans;
uint pw[N],hsh1[N],hsh2[N],P=13331;
map<pair<uint,uint>,int> mp;
uint Hsh(int op,int l,int r){
	int len=r-l+1;
	if(op==1) return hsh1[r]-pw[len]*hsh1[l-1];
	else return hsh2[r]-pw[len]*hsh2[l-1];
}
signed main(){
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;cin>>s1>>s2;
		int l=s1.size();
		uint num1=0,num2=0;
		for(int i=0;i<l;i++) num1=num1*P+s1[i]-'a'+1;
		for(int i=0;i<l;i++) num2=num2*P+s2[i]-'a'+1;
//		cout<<num1<<' '<<num2<<'\n';
		mp[make_pair(num1,num2)]++;
	}
	while(q--){
		string t1,t2;cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<'\n';
			continue;
		}ans=0;
		int len=t1.size();
		t1=' '+t1;t2=' '+t2;
		for(int i=1;i<=len;i++) hsh1[i]=hsh1[i-1]*P+t1[i]-'a'+1;
		for(int i=1;i<=len;i++) hsh2[i]=hsh2[i-1]*P+t2[i]-'a'+1;
		pw[0]=1;for(int i=1;i<=len;i++) pw[i]=pw[i-1]*P;
//		cout<<Hsh(1,1,len)<<' '<<Hsh(2,1,len)<<'\n';
		for(int i=0;i<len;i++) if(Hsh(1,1,i)==Hsh(2,1,i)) ans+=mp[make_pair(Hsh(1,i+1,len),Hsh(2,i+1,len))];
		for(int i=len;i>1;i--) if(Hsh(1,i,len)==Hsh(2,i,len)) ans+=mp[make_pair(Hsh(1,1,i-1),Hsh(2,1,i-1))];
		for(int i=1;i<=len;i++){
			for(int j=i+2;j<=len;j++){
				if(Hsh(1,1,i)==Hsh(2,1,i)&&Hsh(1,j,len)==Hsh(2,j,len)){
					ans+=mp[make_pair(Hsh(1,i+1,j-1),Hsh(2,i+1,j-1))];
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
