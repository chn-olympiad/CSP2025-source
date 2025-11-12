#include<bits/stdc++.h>
using namespace std;
inline long long _(){
	long long f=1,x=0;char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-f;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return f*x;
}
inline void __(long long x,int opt){
	int top=0;
	char st[85];
	if(x<0)putchar('-'),x=-x;
	do{
		st[++top]=x%10;x/=10;
	}while(x);
	for(int i=top;i>=1;i--)putchar(st[i]+'0');
	if(opt==0)return;
	if(opt==1)putchar(' ');
	else putchar('\n');
}
int n,q;
string s[200005],ss[200005],t[200005],tt[200005];
int sizs[200005],sizt[200005];
int ans[200005];
int len1,len2;
long long bas=10559,mod=1000000007;
long long has[200005],hass[200005],pw[5000005];
long long hasfr[200005],hasto[200005];
int sl[200005],sr[200005];
long long b[800005],len;
long long h[5000005],hh[5000005];
map<int,int>mp[800005];
void _25pts(){
	for(int i=1;i<=n;i++){
		int siz=s[i].size();
		for(int j=1;j<=siz;j++)has[i]=(has[i]*bas%mod+s[i][j-1])%mod;
		for(int j=1;j<=siz;j++)hass[i]=(hass[i]*bas%mod+ss[i][j-1])%mod;
		b[++len]=has[i];b[++len]=hass[i];
	}
	sort(b+1,b+len+1);len=unique(b+1,b+len+1)-b-1;
	for(int i=1;i<=n;i++)has[i]=lower_bound(b+1,b+len+1,has[i])-b,hass[i]=lower_bound(b+1,b+len+1,hass[i])-b;
	for(int i=1;i<=n;i++)mp[has[i]][hass[i]]++;
	for(int i=1;i<=q;i++){
		if(t[i].size()!=tt[i].size()){
			__(0,2);
			continue;
		}
		int l=-1,r=-1;
		int siz=t[i].size();
		long long hs=0;
		for(int j=0;j<siz;j++){
			hs=hs*bas%mod;
			hs=hs+(int)t[i][j];hs%=mod;
			h[j]=hs;
		}
		hs=0;
		for(int j=0;j<siz;j++){
			hs=hs*bas%mod;
			hs=hs+(int)tt[i][j];hs%=mod;
			hh[j]=hs;
		}
		for(int j=0;j<siz;j++)if(t[i][j]!=tt[i][j]){
			r=j;
			if(l==-1)l=j;
		}
		long long ans=0;
		for(int ll=0;ll<=l;ll++){
			for(int rr=r;rr<siz;rr++){
				long long ht=(h[rr]-1ll*pw[rr-ll+1]*h[ll-1]%mod+mod)%mod;
				long long htt=(hh[rr]-1ll*pw[rr-ll+1]*hh[ll-1]%mod+mod)%mod;
				int x=lower_bound(b+1,b+len+1,ht)-b;
				int y=lower_bound(b+1,b+len+1,htt)-b;
				if(b[x]!=ht||b[y]!=htt)continue;
				if(!mp[x].count(y))continue;
				ans+=mp[x][y];
			}
		}
		__(ans,2);
	}
}
void _20pts(){
	for(int i=1;i<=n;i++){
		int siz=s[i].size();
		for(int j=1;j<=siz;j++)has[i]=(has[i]*bas%mod+s[i][j-1])%mod;
		for(int j=1;j<=siz;j++)hass[i]=(hass[i]*bas%mod+ss[i][j-1])%mod;
		b[++len]=has[i];b[++len]=hass[i];
		int l=0,r=siz-1;
		while(l<siz&&s[i][l]==ss[i][l])l++;
		while(r>=0&&s[i][r]==ss[i][r])r--;
		sl[i]=l;sr[i]=siz-1-r;
		//cout<<sl[i]<<' '<<sr[i]<<' '<<l<<' '<<r<<endl;
		if(l>r)continue;
		for(int j=l;j<=r;j++)hasfr[i]=(hasfr[i]*bas%mod+s[i][j])%mod;
		for(int j=l;j<=r;j++)hasto[i]=(hasto[i]*bas%mod+ss[i][j])%mod;
		b[++len]=hasfr[i];b[++len]=hasto[i];
	}
	sort(b+1,b+len+1);len=unique(b+1,b+len+1)-b-1;
	for(int i=1;i<=n;i++){
		has[i]=lower_bound(b+1,b+len+1,has[i])-b;
		hass[i]=lower_bound(b+1,b+len+1,hass[i])-b;
		hasfr[i]=lower_bound(b+1,b+len+1,hasfr[i])-b;
		hasto[i]=lower_bound(b+1,b+len+1,hasto[i])-b;
		mp[has[i]][hass[i]]++;
	}
	for(int i=1;i<=q;i++){
		if(t[i].size()!=tt[i].size()){
			__(0,2);
			continue;
		}
		int l=-1,r=-1;
		int siz=t[i].size();
		long long hs=0;
		for(int j=0;j<siz;j++){
			hs=hs*bas%mod;
			hs=hs+(int)t[i][j];hs%=mod;
			h[j]=hs;
		}
		hs=0;
		for(int j=0;j<siz;j++){
			hs=hs*bas%mod;
			hs=hs+(int)tt[i][j];hs%=mod;
			hh[j]=hs;
		}
		for(int j=0;j<siz;j++)if(t[i][j]!=tt[i][j]){
			r=j;
			if(l==-1)l=j;
		}
		int ans=0;
		for(int j=1;j<=n;j++){
			int ll=l-sl[j],rr=r+sr[j];
			if(ll<0||rr>=siz)continue;
		//	cout<<ll<<' '<<rr<<endl;
			long long ht=(h[rr]-1ll*pw[rr-ll+1]*h[ll-1]%mod+mod)%mod;
			long long htt=(hh[rr]-1ll*pw[rr-ll+1]*hh[ll-1]%mod+mod)%mod;
			int x=lower_bound(b+1,b+len+1,ht)-b;
			int y=lower_bound(b+1,b+len+1,htt)-b;
			if(ht!=b[has[j]]||htt!=b[hass[j]])continue;
			if(b[x]!=ht||b[y]!=htt)continue;
			if(!mp[x].count(y))continue;
		//	cout<<mp[x][y]<<endl;
			ans+=mp[x][y];
		}
		__(ans,2);
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=_();q=_();
	for(int i=1;i<=n;i++)cin>>s[i]>>ss[i],len1+=s[i].size()+ss[i].size();
	for(int i=1;i<=q;i++)cin>>t[i]>>tt[i],len2+=t[i].size()+tt[i].size();
	for(int i=1;i<=q;i++)sizs[i]=s[i].size(),sizt[i]=t[i].size();
	pw[0]=1;
	for(int i=1;i<=5000000;i++)pw[i]=pw[i-1]*bas%mod;
//	_20pts();
	if(n<=1000&&q<=1000&&len1<=2000&&len2<=2000){
		_25pts();
		return 0;
	}
	if(q==1){
		_20pts();
		return 0;
	}
}
