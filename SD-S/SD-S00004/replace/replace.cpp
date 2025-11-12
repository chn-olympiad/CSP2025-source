#include<iostream>
#include<cstdio>
#include<unordered_map>
#include<cstring>

#define uint unsigned long long

using namespace std;

inline int Rd(){
	int x=0,f=1; char c=getchar();
	while (c<'0' || c>'9'){
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+(c^'0');
		c=getchar();
	}
	return x*f;
}

int n,q,ans;
uint fac[202],hh[2][1003],hsh[2][1003];
char s1[202],s2[202];

unordered_map<uint,int> mp1,mp2;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	fac[0]=1;
	for (int i=1;i<=300;i++){
		fac[i]=fac[i-1]*13331ull;
	}
	n=Rd(); q=Rd();
	for (int i=1;i<=n;i++){
		scanf(" %s %s",s1+1,s2+1);
		for (int j=1;j<=strlen(s1+1);j++){
			hh[0][i]=hh[0][i]*13331ull+s1[j];
		}hh[0][i]=hh[0][i]*fac[300-strlen(s1+1)+1];
		mp1[hh[0][i]]++;
		
		for (int j=1;j<=strlen(s2+1);j++){
			hh[1][i]=hh[1][i]*13331ull+s2[j];
		}hh[1][i]=hh[1][i]*fac[300-strlen(s2+1)+1];
		mp2[hh[1][i]]++;
	}
	for (int Q=1;Q<=q;Q++){
		scanf(" %s %s",s1+1,s2+1);
		for (int i=1;i<=strlen(s1+1);i++){
			hsh[0][i]=hsh[0][i-1]*s1[i];
			hsh[1][i]=hsh[1][i-1]*s2[i];
		}
		for (int l=1;l<=n;l++){
			for (int r=l;r<=n;r++){
				if ((mp1.find((hsh[0][r]-hsh[0][l]*fac[r-l])*fac[300-r+1])!=mp1.end()) && (mp2.find((hsh[1][r]-hsh[1][l]*fac[r-l])*fac[300-r+1])!=mp2.end())){
					ans=ans+mp1[(hsh[0][r]-hsh[0][l]*fac[r-l])*fac[300-r+1]];
				}
			}
		}printf("%d\n",ans);
	}
	
	return 0;
}
/*
还剩10min
2023年我同学写了 game.ans
上了SD奇葩行为大赏
2024年他写他自己写了game.ans
又上了
2025年他说他还要写
他今年是SD-S01020
快去看他的代码 
*/
