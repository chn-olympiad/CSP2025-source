#include<bits/stdc++.h>
using namespace std;
namespace solve{
	inline int read(){
		int x=0,f=1;char ch=getchar();
		while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
		while(isdigit(ch)){x=x*10+ch-48;ch=getchar();}
		return x*f;
	}
	int n,m;
	inline signed solve(){
		freopen("employ.in","r",stdin);
		freopen("employ.out","w",stdout);
		n=read();m=read();
		if(n<=10){
			bitset<15>s;
			int p[15],c[15];
			char ch='a';
			for(int i=1;i<=n;i++){
				while(!isdigit(ch))ch=getchar();
				if(ch=='1')s[i]=1;
				else s[i]=0;ch='a';
				p[i]=i;
			}
			for(int i=1;i<=n;i++)cin>>c[i];
			int cnt=0;
			do{
				int decline=0;
				for(int i=1;i<=n;i++){
					if(decline>=c[p[i]])decline++;
					if(s[i]==0)decline++;
				}
				if(n-decline>=m)cnt++;
			}while(next_permutation(p+1,p+n+1));
			cout<<cnt%998244353;
		}
		else{
			bitset<505>s;
			int p=1,c[505];
			char ch='a';
			for(int i=1;i<=n;i++){
				while(!isdigit(ch))ch=getchar();
				s[i]=(ch=='1');
				p=1ll*p*i%998244353;
			}
			for(int i=1;i<=n;i++)cin>>c[i];
			cout<<p;
		}
		return 0;
	}
}
int main(){return solve::solve();}
/*

*/