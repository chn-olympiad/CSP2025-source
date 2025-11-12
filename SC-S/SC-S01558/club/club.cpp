#include<bits/stdc++.h> 
using namespace std;

#define Fre(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout);

const int N=1e5+10;

int T,n;
int a[N][3];

int main(){
	Fre("club");
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int s0=0,s1=0,s2=0;
		int c0=0,c1=0,c2=0;
		for(int i=1;i<=n;++i){
			scanf("%d%d%d",a[i],a[i]+1,a[i]+2);
			int A=a[i][0],B=a[i][1],C=a[i][2],mx=max({A,B,C});
			if(A==mx) ++c0,s0+=A;
			else if(B==mx) ++c1,s1+=B;
			else ++c2,s2+=C;
		}
//		printf("%d %d %d %d %d %d\n",c0,s0,c1,s1,c2,s2);
		int m=n>>1;
		if(max({c0,c1,c2})<=m) printf("%d\n",s0+s1+s2);
		else{
			int o=(c0>m?0:(c1>m?1:2));
			int o1=(o+1)%3,o2=(o1+1)%3; 
			static int b[N];
			int cnt=0;
			for(int i=1;i<=n;++i)
				if(a[i][o]-max(a[i][o1],a[i][o2])>=0)
					b[++cnt]=a[i][o]-max(a[i][o1],a[i][o2]);
			sort(b+1,b+cnt+1);
			int k=max({c0,c1,c2})-m,res=s0+s1+s2;
			for(int i=1;i<=k;++i) res-=b[i];
			printf("%d\n",res);
		}
	}
	
	return 0;
}