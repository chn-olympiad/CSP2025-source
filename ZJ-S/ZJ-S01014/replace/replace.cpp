#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
const int N=200055,L=599066;
const int K1=131,K2=137,M=1e9+9;
char s1[L],s2[L],t1[N],t2[N];
ll hs1[L],hs2[L],ht1[N],ht2[N];//hash[i][0~j-1]
int ls[N],ss[N],lt;//len
int Kx1,Kx2,n,q;
ll qpow(ll a,int b,ll m=M){
	ll c=1;
	for(;b;a=a*a%M,b>>=1)
		if(b&1)c=c*a%M;
	return c;
}
void hsh(char s[],ll h[],int l){
	h[0]=0;
	for(int i=0;i<l;i++)
		h[i+1]=(h[i]+s[i]*qpow(K1,i))%M;
}
ll hh(ll h[],int st,int ed){return (h[ed]-h[st])*qpow(Kx1,st);}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	Kx1=qpow(K1,M-2);Kx2=qpow(K2,M-2);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s%s",s1+ss[i],s2+ss[i]);ls[i]=strlen(s1+ss[i]);
		hsh(s1+ss[i],hs1+ss[i],ls[i]);hsh(s2+ss[i],hs2+ss[i],ls[i]);
		ss[i+1]=ss[i]+ls[i]+3;
	}
	for(int j=1;j<=q;j++){
		scanf("%s%s",t1,t2);lt=strlen(t1);
		hsh(t1,ht1,lt);hsh(t2,ht2,lt);
		int k1=0,k2=lt-1;ll ans=0;
		for(;k1<lt&&ht1[k1]==ht2[k1];k1++);//t1[0~k1-1]==t2[0~k1-1]
		for(;k2>=0&&hh(ht1,k2,lt)==hh(ht2,k2,lt);k2--);k2++;//t1[k2~n-1]==t2[k2~n-1]
		for(int i=1;i<=n;i++){
			for(int k=max(0,k2-ls[i]);k<=min(lt-ls[i],k1);k++){//0~k-1;k~k+ls[i]-1;k+ls[i]~lt-1
				if(hh(ht1,k,k+ls[i])==hs1[ss[i]+ls[i]]&&hh(ht2,k,k+ls[i])==hs2[ss[i]+ls[i]])ans++;
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
