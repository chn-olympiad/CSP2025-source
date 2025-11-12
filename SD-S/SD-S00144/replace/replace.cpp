#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();return x*f;
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("replace.in","r",stdin);freopen("replace.out","w",stdout);
	return 0;
} 
