#include<bits/stdc++.h>
#define int unsigned long long
#define ufor(i,x,y) for(int i=x;i<=y;i++)
#define dfor(i,x,y) for(int i=x;i>=y;i--)
#define P 13331
#define mid ((l+r)>>1)
using namespace std;
int out[100];
inline void write(int x){
	int tp=0;
	do{out[++tp]=x%10+'0';x/=10;}while(x);
	while(tp)putchar(out[tp--]);
}
const int N=2e5+5;
int n,q,len,ans;
string s1,s2,t1,t2;
int temp1,temp2,hx,hy;
int lsh[N],rsh[N];
int wow;
struct node{
	int len1,val1,valx,valy,len3,val3;
	inline friend bool operator <(node x,node y){return x.valx<y.valx;}
}a[N];
inline int qp(int x,int y){
	int res=1;
	for(int base=x;y;base*=base,y>>=1)if(y&1)res*=base;
	return res;
}
inline int hs(string s,int l,int r){
	int res=0;
	ufor(i,l,r)res=res*P+s[i]-'a'+1;
	return res;
}
inline int find(int k){
	int l=1,r=n;
	while(l<r){
		if(a[mid].valx<k)l=mid+1;
		else r=mid;
	}
	return l;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	ufor(i,1,n){
		cin>>s1>>s2;len=s1.size();
		if(s1==s2){wow++;continue;}
		temp1=0,temp2=len-1;
		while(s1[temp1]==s2[temp1])temp1++;
		while(s1[temp2]==s2[temp2])temp2--;
		a[i].len1=temp1;
		a[i].val1=temp1==0?0:hs(s1,0,temp1-1);
		a[i].valx=hs(s1,temp1,temp2);
		a[i].valy=hs(s2,temp1,temp2);
		a[i].len3=len-temp2-1;
		a[i].val3=hs(s1,temp2+1,len-1);
	}
	sort(a+1,a+n+1);int beg;
	while(q--){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){putchar('0'),putchar('\n');continue;}
		if(t1==t2){write(wow),putchar('\n');continue;}
		len=t1.size();ans=0;
		temp1=0,temp2=len-1;
		while(t1[temp1]==t2[temp1])temp1++;
		while(t1[temp2]==t2[temp2])temp2--;
		hx=hs(t1,temp1,temp2);
		hy=hs(t2,temp1,temp2);
		lsh[0]=0,rsh[0]=0;
		ufor(i,1,temp1)lsh[i]=lsh[i-1]+(t1[temp1-i]-'a'+1)*qp(P,i-1);
		ufor(i,1,len-temp2-1)rsh[i]=rsh[i-1]*P+t1[temp2+i]-'a'+1;
		beg=find(hx);
		ufor(i,beg,n){
			if(a[i].valx!=hx)break;
			if(a[i].valy!=hy)continue;
			if(temp1<a[i].len1||len-temp2-1<a[i].len3)continue;
			if(lsh[a[i].len1]!=a[i].val1||rsh[a[i].len3]!=a[i].val3)continue;
			ans++;
		}
		write(ans),putchar('\n');
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}