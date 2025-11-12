#include<bits/stdc++.h>
#define F(i,a,b) for(int i=a;i<=b;i++)
#define R(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
typedef long long ll;
const ll N=5e6+7;
const ll basb=131;
const ll basb2=13331;
const ll mod=998244353;
const ll mod2=1e9+7;
ll n,q,has[N],bas[N],has2[N],vis[N],bas2[N],lenc[N],qi[N],ho[N],hav[N],hav2[N],hav3[N],hav4[N],hav5[N],hav6[N],has3[N],has4[N];
string s[N],s2[N],t[N],t2[N];
inline ll fr(){
	ll s=0,k=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') k=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=(s<<3)+(s<<1)+ch-'0';
		ch=getchar();
	}
	return s*k;
}
inline ll get_hash1(ll l,ll r){
	return ((has[r]-(has[l-1]*bas[r-l+1])%mod)+mod)%mod;
}
inline ll get_hash2(ll l,ll r){
	return ((has2[r]-(has2[l-1]*bas2[r-l+1])%mod2)+mod2)%mod2;
}
inline ll get_hash3(ll l,ll r){
	return ((has3[r]-(has3[l-1]*bas[r-l+1])%mod)+mod)%mod;
}
inline ll get_hash4(ll l,ll r){
	return ((has4[r]-(has4[l-1]*bas2[r-l+1])%mod2)+mod2)%mod2;
}
inline void fw(int x){
	if(x>9) fw(x/10);
	putchar((x%10)+'0');
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	bas[0]=1;
	bas2[0]=1;
	F(i,1,1e6){
		bas[i]=bas[i-1]*basb;
		bas[i]%=mod;
		bas2[i]=bas2[i-1]*basb2;
		bas2[i]%=mod2;
	}
	F(i,1,n){
		cin>>s[i]>>s2[i];
		int len=s[i].length();
		s[i]=" "+s[i];
		s2[i]=" "+s2[i];
		int fl=0,la=len,viser=false;
		for(int j=1;j<=len;j++){
			if(!fl&&s[i][j]!=s2[i][j]){
				fl=j;
				viser=true;
			}
			if(viser&&s[i][j]!=s2[i][j]){
				la=j;
			}
		}
		if(!viser){
			vis[i]=true;
		}
		int val1=0,val2=0;
		F(j,fl,la){
			val1=((val1*basb)%mod)+s[i][j];
			val1%=mod;
			val2=((val2*basb2)%mod2)+s[i][j];
			val2%=mod2;
		}
		hav[i]=val1;
		hav2[i]=val2;//s1·Ö´® 
		val1=0,val2=0;
		F(j,1,len){
			val1=((val1*basb)%mod)+s[i][j];
			val1%=mod;
			val2=((val2*basb2)%mod2)+s[i][j];
			val2%=mod2;
		}
		hav3[i]=val1;
		hav4[i]=val2;//s1×Ü´® 
		val1=0,val2=0;
		F(j,fl,la){
			val1=((val1*basb)%mod)+s2[i][j];
			val1%=mod;
			val2=((val2*basb2)%mod2)+s2[i][j];
			val2%=mod2;
		}
		hav5[i]=val1;
		hav6[i]=val2;//s2·Ö´® 
//		cout<<"i:"<<i<<" "<<"fl:"<<fl<<" la:"<<la<<"\n";
		qi[i]=fl-1;
		ho[i]=len-la;
		lenc[i]=la-fl+1;
	}
	F(i,1,q){
		int sum=0;
		cin>>t[i]>>t2[i];
		int len=t[i].length();
		t[i]=" "+t[i];
		t2[i]=" "+t2[i];
		int fl=0,la=len;
		F(j,1,len){
			has[j]=(((has[j-1]*basb)%mod)+t[i][j])%mod;
			has2[j]=(((has2[j-1]*basb2)%mod2)+t[i][j])%mod2;
		}
		F(j,1,len){
			has3[j]=(((has3[j-1]*basb)%mod)+t2[i][j])%mod;
			has4[j]=(((has4[j-1]*basb2)%mod2)+t2[i][j])%mod2;
		}
		F(j,1,len){
			if(!fl&&t[i][j]!=t2[i][j]){
				fl=j;
			}
			if(fl&&t[i][j]!=t2[i][j]){
				la=j;
			}
		}
		F(j,1,n){
//			cout<<"j:"<<j<<" "<<qi[j]<<" "<<ho[j]<<"\n"; 
			if(vis[j]||lenc[j]!=la-fl+1) continue;
			if(fl-qi[j]<=0||la+ho[j]>len){
				continue;
			}
			int hash1=get_hash1(fl-qi[j],la+ho[j]);
			int hash2=get_hash2(fl-qi[j],la+ho[j]);
			int hash3=get_hash3(fl,la);
			int hash4=get_hash4(fl,la);
//			cout<<"i:"<<i<<" j:"<<j<<"\n";
//			cout<<hash1<<" "<<hav3[j]<<"\n";
//			cout<<hash2<<" "<<hav4[j]<<"\n";
//			cout<<hash3<<" "<<hav5[j]<<"\n";
//			cout<<hash4<<" "<<hav6[j]<<"\n";
//			cout<<"\n";
			if(hash1==hav3[j]&&hash2==hav4[j]&&hash3==hav5[j]&&hash4==hav6[j]){
//				if(i==1) cout<<"j:\n"<<t[i]<<"\n"<<t2[i]<<"\n"<<s[j]<<"\n"<<s2[j]<<"\n"<<"\n";
				sum++;
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/
