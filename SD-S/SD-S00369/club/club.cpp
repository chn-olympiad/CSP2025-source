#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
long long read(){
	long long x=0;
	char c=getchar();
	while (c<'0' || c>'9') c=getchar();
	while (c>='0' && c<='9') {
		x*=10;
		x+=(c-'0'); 
		c=getchar();
	}
	return x;
}
const int N=100005;
const int M=200005;
struct club{
	long long a,b,c;
	long long minncost;
}cl[N];
int n;
long long s[5];
int mp[4][N];
long long needturn[N];
long long ans=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=read();
	while (t--){
		memset(mp,0,sizeof(mp));
		ans=0;
		n=read();
	for (int i=1;i<=n;i++){
		cl[i].a=read();
		cl[i].b=read();
		cl[i].c=read();
		s[1]=cl[i].a,s[2]=cl[i].b,s[3]=cl[i].c;
		sort(s+1,s+1+3);
		cl[i].minncost=s[3]-s[2];
		if (s[3]==cl[i].a) mp[1][++mp[1][0]]=i;
		else if (s[3]==cl[i].b) mp[2][++mp[2][0]]=i;
		else if (s[3]==cl[i].c) mp[3][++mp[3][0]]=i;
		ans+=s[3];
	}
	int cnt=0;
	if (mp[1][0]>n/2){
		for (int i=1;i<=mp[1][0];i++) needturn[i]=cl[mp[1][i]].minncost;
		cnt=mp[1][0];
	}
	else if (mp[2][0]>n/2){
		for (int i=1;i<=mp[2][0];i++) needturn[i]=cl[mp[2][i]].minncost;
		cnt=mp[2][0];
	}
	else if (mp[3][0]>n/2){
		for (int i=1;i<=mp[3][0];i++) needturn[i]=cl[mp[3][i]].minncost;
		cnt=mp[3][0];
	}
	sort(needturn+1,needturn+1+cnt);
	for (int i=1;i<=cnt-n/2;i++) ans-=needturn[i];
	printf("%lld\n",ans);
	}
    return 0;
}

