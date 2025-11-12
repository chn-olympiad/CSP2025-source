#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rg register
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x*f;
}
inline void write(int x){
	if(x<0){putchar('-');x=-x;}
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int N=1e5+10;
int n;
signed main(){
	freopen("club.in","r",stdin);freopen("club.out","w",stdout);
	int t=read();
	while(t--){
		int ans=0;
		n=read();
		vector<int>v1;vector<int>v2;vector<int>v3;
		for(rg int i=1;i<=n;i++){
			int d1=read(),d2=read(),d3=read();
			int x=max({d1,d2,d3}),y=min({d1,d2,d3}),z=d1+d2+d3-x-y;
			ans+=x;
			if(x==d1)v1.push_back(x-z);
			if(x==d2&&x!=d1)v2.push_back(x-z);
			if(x==d3&&x!=d1&&x!=d2)v3.push_back(x-z);
		}
		if(v1.size()>n/2){
			sort(v1.begin(),v1.end());
			for(rg int i=0;i<v1.size()-n/2;i++)ans-=v1[i];
		}
		if(v2.size()>n/2){
			sort(v2.begin(),v2.end());
			for(rg int i=0;i<v2.size()-n/2;i++)ans-=v2[i];
		}
		if(v3.size()>n/2){
			sort(v3.begin(),v3.end());
			for(rg int i=0;i<v3.size()-n/2;i++)ans-=v3[i];
		}
		write(ans);
		puts("");
	}
}
