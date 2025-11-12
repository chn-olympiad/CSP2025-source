#include<bits/stdc++.h>
#define endl "\n"
#define f(n) for(int i=1;i<=n;i++)
#define int long long
#define IOS cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
using namespace std;
int n,q,len,ans,c[200005],p;
string s1[200005],s2[200005],t1,t2;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	IOS;cin>>n>>q;
	f(n){
		cin>>s1[i]>>s2[i],s1[i]=" "+s1[i],s2[i]=" "+s2[i];
		for(int j=1;j<=(int)(s1[i].length()-1);j++)if(s1[i][j]!=s2[i][j])c[i]++;
	}
	while(q--){
		cin>>t1>>t2,t1=" "+t1,t2=" "+t2;
		if(t1.length()!=t2.length()){
			cout<<0<<endl;
			continue;
		}
		len=(int)t1.length()-1,ans=0,p=0;
		f(len)if(t1[i]!=t2[i])p++;
		f(n){
			if((int)(s1[i].length()-1)>len||c[i]!=p)continue;
			for(int j=1;j<=len-(int)(s1[i].length()-1)+1;j++){
				int fl=0;
				for(int k=1;k<=(int)(s1[i].length()-1);k++)if(t2[j+k-1]!=s2[i][k]||t1[j+k-1]!=s1[i][k]){fl=1;break;}
				if(!fl)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
