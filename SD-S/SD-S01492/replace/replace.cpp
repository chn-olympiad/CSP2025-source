#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=1;
	char ch=getchar();
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
string s[200005],T[200005];
int cha[200005],qian[200005],hou[200005];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n=read(),q=read();
	int maxsiz=0;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>T[i];
		int ssz=s[i].size();
		maxsiz=max(maxsiz,ssz);
	}
	if(maxsiz<=2000){
		while(q--){
			string t,tt;
			cin>>t>>tt;
			int siz=t.size();
			if(siz!=tt.size()){
				cout<<0<<'\n';
				continue;
			} 
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=0;j<siz;j++){
					int le=s[i].size();
					if(t[j]==s[i][0]&&j+le-1<siz){
						int f=0;
						for(int k=j;k<j+le;k++){
							if(t[k]!=s[i][k-j]){
								f=1;
								break;
							}
						}
						if(!f){
							string qq=t;
							for(int k=j;k<j+le;k++){
								qq[k]=T[i][k-j];
							}
							if(qq==tt) ans++;
						}
					}
				}
			}
			cout<<ans<<'\n';
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		int ssz=s[i].size();
		int s_b=0,T_b=0;
		for(int j=0;j<ssz;j++){
			if(s[i][j]=='b'){
				s_b=j;
				qian[i]=j;
				hou[i]=ssz-j-1;
			} 
			if(T[i][j]=='b') T_b=j;
		}
		cha[i]=s_b-T_b;
	}
	while(q--){
		string t,tt;
		cin>>t>>tt;
		int siz=t.size();
		if(siz!=tt.size()){
			cout<<0<<'\n';
			continue;
		} 
		int t_b=0,tt_b=0,qi=0,ho=0;
		for(int j=0;j<siz;j++){
			if(t[j]=='b'){
				t_b=j;
				qi=j;
				ho=siz-j-1;
			} 
			if(tt[j]=='b') tt_b=j;
		}
		int zh=t_b-tt_b,ans=0;
		for(int i=1;i<=n;i++){
			if(zh==cha[i]&&qi>=qian[i]&&ho>=hou[i]) ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
