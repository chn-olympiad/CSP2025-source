#include<bits/stdc++.h>
typedef long long ll;
const ll N=2e5+10;
using namespace std;
inline ll read(){
	char ch;
	ll f=1,x=0;
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
ll n,q,ans;
string a[N],b[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();
	q=read();
//	string s="YQCCS";
//	s.erase(1,3);
//	cout<<s; 
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	while(q--){
		ans=0;
		string s,t;
		cin>>s>>t;
		ll ls=s.size(),lt=t.size();
		for(ll i=1;i<=n;i++){
			if(s.find(a[i])<ls&&t.find(b[i])<lt){
				string x=s,z=t;
				x.erase(s.find(a[i]),a[i].size());
				z.erase(t.find(b[i]),b[i].size());
				if(x==z)
					ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
