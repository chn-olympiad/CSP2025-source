#include<bits/stdc++.h>

using namespace std;

inline int read(){
	int s=0;char c=getchar();bool f=0;
	while(c<'0'||c>'9'){f=(f||(c=='-'));c=getchar();}
	while(c>='0'&&c<='9'){s=(s<<1)+(s<<3)+(c^48);c=getchar();}
	if(f) s=-s;
	return s;
}


signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cout<<read()*(read()+read())/read()-read()%998244353;
	return 0;
}
/*
0<=k<=10!!!!
*/
