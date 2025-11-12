#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,a[N],b[N],s[N],ans;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch))f=ch=='-'?-f:f,ch=getchar();
	while(isdigit(ch))x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
map<int,int>e;
int main(){
	//freopen
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),k=read();
	int cnt=1;
	for(int i=1;i<=n;i++)a[i]=read(),s[i]=s[i-1]^a[i],b[i]=s[i]^k;
	for(int i=1;i<=n;i++){
		int j;
		for(j=i;j<=n;j++){
			if((s[j]^s[i-1])==k||e[b[j]]==cnt){i=j,ans++;break;}
			e[s[j]]=cnt;
		}
		cnt++;
	}
	cout<<ans<<endl;
	return 0;
}
//I_Love_Furina