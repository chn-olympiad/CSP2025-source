#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define ptc putchar
using namespace std;
const int N=5e6+11;
const int BASE1=13331,BASE2=131;
const int mod1=998244353,mod2=1e9+7;
int n,q;
int len;
char c1[N],c2[N];
map<int,int> mp1,mp2;
ll hash1[N],hash2[N],hash3[N],hash4[N];
ll lc1[N],lc2[N];
int ans;
ll get1(int l,int r){
	return ((hash1[r]-hash1[l-1]*lc1[r-l+1]%mod1)+mod1)%mod1;
}
ll get2(int l,int r){
	return ((hash2[r]-hash2[l-1]*lc1[r-l+1]%mod1)+mod1)%mod1;
}
ll get3(int l,int r){
	return ((hash3[r]-hash3[l-1]*lc2[r-l+1]%mod2)+mod2)%mod2;
}
ll get4(int l,int r){
	return ((hash4[r]-hash4[l-1]*lc2[r-l+1]%mod2)+mod2)%mod2;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	lc1[0]=1;
	lc2[0]=1;
	for(int i=1;i<N-5;i++){
		lc1[i]=lc1[i-1]*BASE1%mod1;
		lc2[i]=lc2[i-1]*BASE2%mod2;
	}
	for(int i=1;i<=n;i++){
		scanf("%s%s",c1+1,c2+1);
		ll h1=0,h2=0,h3=0,h4=0;
		len=strlen(c1+1);
		for(int i=1;i<=len;i++){
			h1=h1*BASE1%mod1+c1[i];
			h1%=mod1;
			h2=h2*BASE1%mod1+c2[i];
			h2%=mod1;
			h3=h3*BASE2%mod2+c1[i];
			h3%=mod2;
			h4=h4*BASE2%mod2+c2[i];
			h4%=mod2;
		}
		mp1[h1]=h2;
		mp2[h3]=h4;
	}
	for(int t=1;t<=q;t++){
		ans=0;
		scanf("%s%s",c1+1,c2+1);
		len=strlen(c1+1);
		int l=len+1,r=0;
		for(int i=1;i<=len;i++){
			if(c1[i]!=c2[i]){
				l=min(l,i);
				r=max(r,i);
			}
		}
		for(int i=1;i<=len;i++){
			hash1[i]=hash1[i-1]*BASE1%mod1+c1[i];
			hash1[i]%=mod1;
			hash2[i]=hash2[i-1]*BASE1%mod1+c2[i];
			hash2[i]%=mod1;
			hash3[i]=hash3[i-1]*BASE2%mod2+c1[i];
			hash3[i]%=mod2;
			hash4[i]=hash4[i-1]*BASE2%mod2+c2[i];
			hash4[i]%=mod2;
		}
//		while(l>0&&r<len){
//			if(mp1[get1(l,r)]&&mp1[get1(l,r)]==get2(l,r)){
//				++ans;
//			}
//			--l;
//			++r;
//		}
		for(int x=1;x<=l;x++){
			for(int y=r;y<=len;y++){
				if(mp1[get1(x,y)]&&mp1[get1(x,y)]==get2(x,y)&&mp2[get3(x,y)]&&mp2[get3(x,y)]==get4(x,y)){
					++ans;
				}
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}