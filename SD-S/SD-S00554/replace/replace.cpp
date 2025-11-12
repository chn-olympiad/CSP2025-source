#include<bits/stdc++.h>
using namespace std;
const int N=5e4+10,Q=2e4+5;
char a[N],b[N];
char s1[N][Q],s2[N][Q];
int nx[10005][Q],n,q;
bool vis[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	int num=1;
	while(n--){
		memset(nx,0,sizeof nx);
		nx[1][num]=0;
		scanf("%s%s",s1[num]+1,s2[num]+1);
		int len=strlen(s2[num]+1);
		for(int i=2,j=0;i<=len;i++){
			if(j+1==i) continue;
			while(j&&s2[j+1][num]!=s2[i][num]) j=nx[num][j];
			if(s2[j+1][num]==s2[i][num]) j++;
			nx[num][i]=j;
		}
		num++;
	}
	while(q--){
		int ans=0;
		memset(vis,0,sizeof vis);
		scanf("%s%s",a+1,b+1);
		int len=strlen(a+1);
		for(int i=1;i<=len;i++){
			if(a[i]!=b[i]) vis[i]=1;
		}
		for(int w=1;w<=n;w++){
			int l=strlen(s2[num]+1);
			for(int i=1,j=0;i<=n;i++){
				while(j&&s2[j+1][num]!=a[i]) j=nx[num][j];
				if(s2[j+1][num]==a[i]) j++;
				if(j==l){
					int sum=0;
					for(int m=i,j=l;m>=i-l;m--,j--) if(s2[j][num]==a[m]) sum++;
					if(sum==l) ans++;
				}
				
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
