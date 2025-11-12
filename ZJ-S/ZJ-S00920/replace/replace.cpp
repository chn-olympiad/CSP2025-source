#include <bits/stdc++.h>
#define ull unsigned long long
#define puu pair<ull,ull>
#define fst first
#define scd second
using namespace std;
inline int read(){
	char c=getchar();
	int x=0,f=1;
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+c-48,c=getchar();
	return x*f;
}
inline void print(const int x){
	if(x==0){putchar('0');return;}
	int t=x;
	if(t<0)t=-t,putchar('-');
	int num[40],len=0;
	while(t)num[len++]=t%10+48,t/=10;
	while(len--)putchar(num[len]);
}
const int N=2e5+5,M=5e6+5;
const ull base1=97,base2=1145147;

ull p1[M],p2[M];
ull h1[M],h2[M];

map<puu,vector<pair<puu,puu>>>mp;

char s1[M],s2[M];

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n=read(),q=read();
	p1[0]=p2[0]=1;
	for(int i=1;i<M;i++){
		p1[i]=p1[i-1]*base1;
		p2[i]=p2[i-1]*base2;
	}
	puu t1;
	pair<puu,puu> t2;
	for(int i=1,l,r;i<=n;i++){
		scanf("%s",s1+1);
		scanf("%s",s2+1);
		int len=strlen(s1+1);
//		printf("len:%d\n",len);
//		if(i==3)continue;
		for(int j=1;j<=len;j++)
			if(s1[j]!=s2[j])goto fr;
		continue;
		fr:;
		l=0;
		for(int j=1;j<=len;j++)
		if(s1[j]!=s2[j]){l=j;break;}
		r=0;
		for(int j=len;j;j--)
		if(s1[j]!=s2[j]){r=j;break;}
		t2.fst.fst=l-1;
		t2.scd.fst=len-r;
		t2.fst.scd=t2.scd.scd=0;
		for(int j=1;j<l;j++)t2.fst.scd=t2.fst.scd*base1+s1[j]-'a'+1;
		for(int j=r+1;j<=len;j++)t2.scd.scd=t2.scd.scd*base2+s1[j]-'a'+1;
		t1.fst=t1.scd=0;
		for(int j=l;j<=r;j++)t1.fst=t1.fst*base1+s1[j]-'a'+1;
		for(int j=l;j<=r;j++)t1.scd=t1.scd*base2+s2[j]-'a'+1;
		mp[t1].emplace_back(t2);
//		printf("%d %d\n",l,r);
//		printf("%llu %llu\n",t1.fst,t1.scd);
	}
	while(q--){
		int ans=0;
		scanf("%s",s1+1);
		scanf("%s",s2+1);
		int len=strlen(s1+1);
		int l=0;
		for(int j=1;j<=len;j++)
		if(s1[j]!=s2[j]){l=j;break;}
		int r=0;
		for(int j=len;j;j--)
		if(s1[j]!=s2[j]){r=j;break;}
		for(int j=1;j<=len;j++)h1[j]=h1[j-1]*base1+s1[j]-'a'+1;
		for(int j=1;j<=len;j++)h2[j]=h2[j-1]*base2+s1[j]-'a'+1;
		t1.fst=t1.scd=0;
		for(int j=l;j<=r;j++)t1.fst=t1.fst*base1+s1[j]-'a'+1;
		for(int j=l;j<=r;j++)t1.scd=t1.scd*base2+s2[j]-'a'+1;
		auto tv=mp[t1];
		for(auto i:tv){
			if(i.fst.fst>=l||h1[l-1]-h1[l-1-i.fst.fst]*p1[i.fst.fst]!=i.fst.scd)continue;
			if(i.scd.fst>len-r||h2[r+i.scd.fst]-h2[r]*p2[i.scd.fst]!=i.scd.scd)continue;
			++ans;
		}
		print(ans),putchar('\n');
	}
	return 0;
}
