//by SmileMask
#include<bits/stdc++.h>
using namespace std;

namespace SmileMask{
	#define rd read()
	int read(){
		int num=0,sign=1;char ch=getchar();
		while(!isdigit(ch)){
			if(ch=='-') sign=-1;
			ch=getchar();
		}
		while(isdigit(ch)){
			num=(num<<3)+(num<<1)+ch-'0';
			ch=getchar();
		}
		return num*sign;
	}
	
	const int N=510;
	
	int n,m,c[N];
	char s[N];
	
	namespace Sub1_5{
		const int M=18;
		
		const int mod=998244353;
		int f[1<<M][M];
		
		void add(int &x,int y){
			x+=y;if(x>=mod) x-=mod;
		}
		
		void Main(){
			f[0][0]=1;
			for(int S=0;S<(1<<n);S++){
				for(int x=0;x<=n;x++){
					if(f[S][x]==0)
						continue;
//					cout<<S<<' '<<x<<endl;
					int ll=__builtin_popcount(S);
					for(int i=0;i<n;i++){
						if(S>>i&1) continue;
						add(f[S|(1<<i)][x+((s[ll+1]=='0')||(c[i+1]<=x))],f[S][x]);
					}
				}
			}
			int ans=0;
			for(int x=0;x<=n-m;x++)
				add(ans,f[(1<<n)-1][x]);
			cout<<ans<<endl;
		}
	}

	void Main(){
		n=rd,m=rd;
		scanf("%s",s+1);
		for(int i=1;i<=n;i++)
			c[i]=rd;
		if(n<=18) Sub1_5::Main();	
		
	}
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	SmileMask::Main();
	return 0;
}
/*
还有105min
60min给T3,45min 给 T4 
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/ 


