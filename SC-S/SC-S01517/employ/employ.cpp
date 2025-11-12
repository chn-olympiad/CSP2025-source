#include<bits/stdc++.h>
#define N 510
using namespace std;
int n,m,c[N]; char s[N];  
int main(){
	freopen("employ.in","r",stdin); freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m>>(s+1); for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=10){
		int p[19],ans=0; for(int i=1;i<=n;i++) p[i]=i;
		do{
			int L=0,cnt=0;
			for(int j=1;j<=n;j++){
				if(L>=c[p[j]]){L++;continue;}
				if(s[j]=='1') cnt++; else L++;
			} ans+=cnt>=m;
		}while(next_permutation(p+1,p+n+1)); cout<<ans<<endl;
	}else{ bool flag=1; for(int i=1;i<=n;i++) flag&=s[i]=='1';
		for(int i=1;i<=n;i++) flag&=c[i]!=0;
		long long sum=1; for(int i=1;i<=n;i++) sum=sum*i%998244353;
		if(m==n) cout<<(flag?sum:0)<<endl;
	}
	return 0;
}