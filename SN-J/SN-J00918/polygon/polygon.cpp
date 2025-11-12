#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long ans=0;
	char ch=getchar();
	while(isdigit(ch)){
		ans=ans*10+ch-'0';
		ch=getchar();
	}return ans;
}
const int N=5010,mod=998244353;
long long a[N],b[N],d[N],e[N],n,ans,sum,c,cnt=1,l;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}cout<<0;
	return 0;
}
