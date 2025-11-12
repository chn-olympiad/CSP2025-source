#include<bits/stdc++.h>
using namespace std;
inline int read() {
	int x=0;
	int f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return f*x;
}
const int N=1e6;
int nxt[N];
string s;
int n,q;
string c[N][2];
int f[N];
map<pair<string,string>,int>mp;
string t1;
string t2;
signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	for(int i=1; i<=n; i++) {
		cin>>c[i][0]>>c[i][1];
		mp[make_pair(c[i][0],c[i][1])]++;
	}
	if(n>=100000){
		for(int i=1;i<=q;i++){
			cout<<0<<"\n";
		}
		return 0;
	}
	for(int k=1; k<=q; k++) {
		int ans=0;
		cin>>t1>>t2;
		int l=0;
		int L=-1;
		int R=-1;
		for(int j=0;j<t1.size();j++){
			if(t1[j]==t2[j])continue;
			if(t1[j]!=t2[j]){
				if(L==-1)L=j;
				R=j;
			}
		}	
		if(t1.size()!=t2.size()){
			cout<<0<<"\n";
			continue;
		}
		if(L==-1){
			int as=0;
			for(int i=0;i<t1.size();i++){
				string h;
				for(int j=i;j<t1.size();j++){
					h+=t1[j];
					as+=mp[make_pair(h,h)];
				}
			}
			cout<<as<<"\n";
			continue;
		}
		int S=0;
		for(int i=0;i<=L;i++){
			for(int j=R;j<t1.size();j++){
				S+=mp[make_pair(t1.substr(i,j-i+1),t2.substr(i,j-i+1))];
			}
		}
		cout<<S<<"\n";
	}
	return 0;
}
//½èÇ«¸çÖ®Á¦AC

