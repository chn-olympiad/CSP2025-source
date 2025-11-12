#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
bool Men;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-') f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}

const int N=500005;

int mp[10000007]; 

int n,k,a[N],s[N];

bool Mbe;
signed main(){
//	freopen("xor6.in","r",stdin);
//	freopen("test.ans","w",stdout);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]^a[i];
	}
	mp[0]=1;
	int ans=0,lst=0;
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			ans++;
			lst=i;
			mp[s[i]]=i+1;
			continue;
		}
		int xiangyao=(k^s[i]);
		if(mp[xiangyao]>lst){
			ans++;
			lst=i;
		}
		mp[s[i]]=i+1;
//		cout<<i<<' '<<ans<<endl;
	}
	
	cout<<ans<<endl;
	
	
	return 0;
} 
