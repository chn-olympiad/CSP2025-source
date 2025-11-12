#include<bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;
bool Men;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-') f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
const int mod=998244353;
const int N=200005;
int n,m;
string s;
int c[N],p[N];
bool Mbe;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
//	printf("%.8lfMB\n",(&Mbe-&Men)/1000000.0);
	n=read(),m=read();
	cin>>s;
	int ans=0;
	for(int i=1;i<=n;i++) p[i]=i;
	for(int i=1;i<=n;i++) cin>>c[i];
	do{
		int cnt=0,tot=0;
		for(int i=1;i<=n;i++){
			int nowat=p[i];
			if(cnt>=c[p[i]]) cnt++;
			else{
				if(s[i-1]=='1') tot++;
				else cnt++;
			}
		}
		if(tot>=m) ans=(ans+1)%mod;
	}while(next_permutation(p+1,p+1+n));
	cout<<ans<<endl;
	
	return 0;
} 
