#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
void read(int &x){
	x=0;ll sign=1;char ch=getchar();
	while(!(ch>='0'&&ch<='9')){
		if(ch=='-')sign=-1;
		ch=getchar();
	}
	while((ch>='0'&&ch<='9')){
		x=x*10+(ch^48);
		ch=getchar();
	}
	x=x*sign;
}
void read(ll &x){
	x=0;ll sign=1;char ch=getchar();
	while(!(ch>='0'&&ch<='9')){
		if(ch=='-')sign=-1;
		ch=getchar();
	}
	while((ch>='0'&&ch<='9')){
		x=x*10+(ch^48);
		ch=getchar();
	}
	x=x*sign;
}
const int N=3e5+5;
string s[N][3];
int len[N],cc[N],cc1[N],n,q;
string t,tt;
signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	double c=clock();
	read(n);read(q);
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		len[i]=s[i][1].length();
		s[i][1]=" "+s[i][1];
		s[i][2]=" "+s[i][2];
		int ck=len[i]+1;
		for(int j=1;j<=len[i];j++){
			if(s[i][1][j]!=s[i][2][j]){
				ck=j;
				break;
			}
		}
		cc[i]=ck;
		ck=0;
		for(int j=len[i];j>=1;j--){
			if(s[i][1][j]!=s[i][2][j]){
				ck=j;
				break;
			}
		}
		cc1[i]=ck;
	//	cout<<cc[i]<<" "<<cc1[i]<<endl;
	}
	while(q--){
		cin>>t>>tt;
		int len1=t.length();
		t=" "+t;
		tt=" "+tt;
		if(t.length()!=tt.length()){
			puts("0");
			continue;
		}
		int l=len1+1;
		for(int j=1;j<=len1;j++){
			if(t[j]!=tt[j]){
				l=j;
				break;
			}
		}
		int r=0;
		for(int j=len1;j>=1;j--){
			if(t[j]!=tt[j]){
				r=j;
				break;
			}
		}
		//cout<<l<<" "<<r<<endl;
		ll ans=0;
		for(int i=1;i<=n;i++){
			if(cc1[i]-cc[i]!=r-l)continue;
			if(l-1<(cc[i]-1))continue;
			if(len[i]-cc1[i]>len1-r)continue;
			int ck=0;
			for(int j=1;j<=len[i];j++){
				if(s[i][1][j]!=t[l-cc[i]+j]){
					ck=-1;break;
				}
				if(s[i][2][j]!=tt[l-cc[i]+j]){
					ck=-1;break;
				}
			}
			if(ck==0)ans++;
		}
		printf("%lld\n",ans);
	} 
	return 0;
}


