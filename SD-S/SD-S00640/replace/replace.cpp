#include<bits/stdc++.h>
#define int long long
#define _(x,y) ((((x)-(y))%mod+mod)%mod)
using namespace std;

inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<48){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>47) x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x*f;
}

inline void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}

const int N=2e5+5;
const int L=5e6+6;
const int B=131;
const int mod=1e9+9;
int n,q,hs[2][N],pw[L],hs1[L],hs2[L],LEN[N];
char s1[L],s2[L];

inline int HASH1(int l,int r){
	return _(hs1[r],hs1[l-1]*pw[r-l+1]%mod);
}

inline int HASH2(int l,int r){
	return _(hs2[r],hs2[l-1]*pw[r-l+1]%mod);
}

inline int solve(int id,int len,int l,int r){
	//检查当前询问里，如果拿id这一对换的话，有多少情况
	int Len=LEN[id];
	if(LEN[id]<r-l+1){
		return 0;
	}
	int ans=0;
	for(int i=1;i<=len;i++){
		hs1[i]=(hs1[i-1]*B%mod+(s1[i]-'a'+1))%mod;
		hs2[i]=(hs2[i-1]*B%mod+(s2[i]-'a'+1))%mod; 
	}
	for(int i=r;i<=len&&i-Len+1<=l;i++){
		if((hs[0][id]==HASH1(i-Len+1,i))&&(hs[1][id]==HASH2(i-Len+1,i))){
			ans++;
		}
	}
	return ans;
}

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	pw[0]=1;
	for(int i=1;i<=5000000;i++){
		pw[i]=pw[i-1]*B%mod;
	}
	for(int i=1;i<=n;i++){
		scanf("%s%s",s1+1,s2+1);
		int len=strlen(s1+1);
		LEN[i]=len;
		for(int j=1;j<=len;j++){
			hs[0][i]=(hs[0][i]*B%mod+(s1[j]-'a'+1))%mod;
			hs[1][i]=(hs[1][i]*B%mod+(s2[j]-'a'+1))%mod;
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%s%s",s1+1,s2+1);
		int len1=strlen(s1+1);
		int len2=strlen(s2+1);
		if(len1!=len2){
			printf("0\n");
			continue;
		}
		int l=0,r=0,len=len1;
		for(int i=1;i<=len;i++){
			if(s1[i]!=s2[i]){
				l=i;break;
			}
		}
		for(int i=len;i>=1;i--){
			if(s1[i]!=s2[i]){
				r=i;break;
			}
		}
		int ans=0;
		for(int j=1;j<=n;j++){
			ans+=solve(j,len1,l,r);
		}
		printf("%lld\n",ans);
	}	
	return 0;
} 
