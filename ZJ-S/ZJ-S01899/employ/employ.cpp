#include<bits/stdc++.h>
#define il inline
#define int long long
#define pii pair<int,int>
#define mk make_pair
#define fir first
#define sec second
#define put putchar
using namespace std;
il int rd(){
	int sum=0,p=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')p=-1;ch=getchar();}
	while(isdigit(ch)){sum=sum*10+(ch-'0');ch=getchar();}
	return sum*p;
}
il void wr(int x){
	if(x<0)put('-'),x=-x;
	if(x>9)wr(x/10);
	put(x%10+'0');
}
const int JYAAKIOI=1e18,N=1e3+10,M=1e4+10,mod=998244353;
int n,m,c[N],p[N],ans;
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=rd();m=rd();
	cin>>s;
	for(int i=1;i<=n;++i)c[i]=rd();
	for(int i=1;i<=n;++i)p[i]=i;
	if(n<=10){	
		do{
			int sum1=0,sum2=0;
			for(int i=1;i<=n;++i){
				int now=p[i];
				if(sum2>=c[now]||s[i-1]=='0'){
					++sum2;
					continue;
				}
				else ++sum1;
			}
			if(sum1>=m)++ans;
		}while(next_permutation(p+1,p+1+n));
	}
	else{
		ans=1;
		for(int i=1;i<=n;++i)ans=ans*i%mod;
	}
	wr(ans);
	return 0;
}
