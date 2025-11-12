#include<bits/stdc++.h>
#define int long long
#define fast register int
using namespace std;
const int maxn=2e5+5;

int n,q,fr[maxn],ba[maxn];
string s1[maxn],s2[maxn];
string t1,t2;

inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*w;
}

inline void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar('0'+x%10);
}

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(fast i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(fast i=1;i<=q;i++){
		cin>>t1>>t2;
		int ans=0;
		for(fast j=1;j<=n;j++){
			string t=t1;
			int x=t.find(s1[j]);
			int len=s1[j].size();
			if(x<=len){
				for(fast k=0;k<len;k++){
					t[x+k]=s2[j][k];
				}
			}
			if(t==t2) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}