#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}
const int N=1e6+5;
int n,q,a[N],sa[N],ta,tta,len[N];
string s[N],ss[N],t[N],tt[N];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	for(int i=1;i<=n;++i){
		cin>>s[i]>>ss[i];
		len[i]=s[i].size();
		for(int j=0;j<len[i];++j){
			if(s[i][j]=='b'){
				a[i]=j;
			}
			if(ss[i][j]=='b'){
				sa[i]=j;
			}
		} 
	}
	for(int i=1;i<=q;++i){
		cin>>t[i]>>tt[i];
		int ans=0;
		int len1=t[i].size(),len2=tt[i].size();
		if(len1!=len2){
			printf("0\n");
			continue;
		}
		for(int j=1;j<=len1;++j){
			if(t[i][j]=='b'){
				ta=j;
			}
			if(tt[i][j]=='b'){
				tta=j;
			}
		}
		for(int j=1;j<=n;++j){
			if(len[i]-sa[i]+1==tta-ta+1||len[i]-a[i]+1==tta-ta+1){
				ans++;
			}
		}
		printf("%lld",ans);
	}
	return 0;
}
