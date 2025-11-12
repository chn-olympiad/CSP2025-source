#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q,step[200005],step2[200005],nxt[200005],len2[200005];
char s1[1005][2005],s2[1005][2005],a[2005],b[2005];
bool flag[2005];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string a,b;
		cin>>a>>b;
		int len=a.size();
		len2[i]=len;
		for(int j=1;j<=len;j++)s1[i][j]=a[j-1];
		for(int j=1;j<=len;j++)s2[i][j]=b[j-1];
	}
	while(q--){
		string a,b,t1,t2;
		cin>>a>>b;
		int len=a.size();
		for(int i=1;i<=len;i++)t1[i]=a[i-1];
		for(int i=1;i<=len;i++)t2[i]=b[i-1];
		flag[len+1]=1;
		for(int i=1;i<=len;i++){
			flag[i]=1;
			for(int j=i;j<=len;j++){
				if(t1[j]!=t2[j])flag[i]=0;
			}
		}
		int ans=0;
		for(int k=1;k<=n;k++){
			int cnt=0,cnt2=0;
			int len2=::len2[k];
			for(int i=1;i<=len2;i++){
				a[i]=s1[k][i];
				b[i]=s2[k][i];
			}
			nxt[1]=0;
			for(int i=2;i<=len2;i++){
				int j=nxt[i-1];
				while(j&&a[j+1]!=a[i])j=nxt[j];
				if(a[j+1]==a[i])j++;
				nxt[i]=j;
			}
			for(int i=1,j=1;i<=len;i++){
				while(j&&a[j+1]!=t1[i])j=nxt[j];
				if(a[j+1]==t1[i])j++;
				if(j==len2){
					step[++cnt]=i-len2+1;
					j=nxt[j];
				}
			}
			nxt[1]=0;
			for(int i=2;i<=len2;i++){
				int j=nxt[i-1];
				while(j&&b[j+1]!=b[i])j=nxt[j];
				if(b[j+1]==b[i])j++;
				nxt[i]=j;
			}
			for(int i=1,j=1;i<=len;i++){
				while(j&&b[j+1]!=t2[i])j=nxt[j];
				if(b[j+1]==t2[i])j++;
				if(j==len2){
					step2[++cnt2]=i-len2+1;
					j=nxt[j];
				} 
			}
			int j=1;
			for(int i=1;i<=cnt;i++){
				for(;j<=cnt2;j++){
					if(step[i]==step2[j]&&flag[step[i]+len2])ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
}
