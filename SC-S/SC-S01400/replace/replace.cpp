#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=(s<<1)+(s<<3)+(ch^48);ch=getchar();}
	return s*f;
}
const int N=1e5+5;
int n,q;
string s[N][2],st,ed;
int len;
int ll[N],ans;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) {
		cin>>s[i][0]>>s[i][1];
		ll[i]=s[i][0].size();
	}
	if(n>=200000){
		while(q--) cout<<"0\n";
		return 0;
	}
	while(q--){
		cin>>st>>ed;
		int m=st.size();
		if(m>=1000&&n>=1000){
			cout<<"0\n";
			continue;
		}
		ans=0;
		st=' '+st,ed=' '+ed;
		for(int i=1;i<=n;i++){
			string sdf=st;
			for(int k=1;k<=m-ll[i]+1;k++){
				for(int j=0;j<ll[i];j++){
					if(s[i][0][j]!=st[k+j]) goto tail;
					else st[k+j]=s[i][1][j];
				}
				if(st==ed) ans++;
				tail:
					st=sdf;
					continue;
			}
		} 
		cout<<ans<<'\n';
	}
	return 0;
}
