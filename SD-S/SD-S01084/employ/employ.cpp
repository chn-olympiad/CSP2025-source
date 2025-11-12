#include<bits/stdc++.h>
#define ll long long
using namespace std;
template<typename T>inline void read(T &n);
const int MOD=998244353;
const int N=505;
char s[505];
int c[N],p[N];
bool isA=1;
int main(){
	//freopen("debug.in","r",stdin);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>s[i];
	}
	for (int i=1;i<=n;i++) cin>>c[i];
	for (int i=1;s[i];i++) if (s[i]=='0') isA=0;
	if (isA){//´íÎó 
		ll ans=1;
		for (ll i=2;i<=n;i++) ans=(ans*i)%MOD;
		cout<<ans;
	}else if (n<=10){
		int ans=0;
		for (int i=1;i<=n;i++) p[i]=i;
		do{
			int l=0;
			for (int i=1;i<=n;i++){
				if (l>=c[p[i]]||s[p[i]]=='0') l++;
			}
			if (n-l>=m){
				ans++;
			}
		}while (next_permutation(p+1,p+n+1));
		printf("%d",ans);
	}
	return 0;
 }
template<typename T>inline void read(T &n){
	n=0;char c;
	T f=1;
	do{
		c=getchar();
		if (c=='-') f=-1;
	}while (c>'9'||c<'0');
	while (c>='0'&&c<='9'){
		n=(n<<1)+(n<<3)+(c^48);
		c=getchar();
	}
	n*=f;
}

