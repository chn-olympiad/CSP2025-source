#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5,base=127;
typedef unsigned long long ull;
ull hsh,a[N][5],mi[N],ha[N],t;
int n,q;
char s[N],ss[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		int l=strlen(s+1);
		hsh=0;
		for(int j=1;j<=l;j++)
			hsh=hsh*base+s[i];
		a[i][1]=hsh;a[i][3]=l;
		scanf("%s",s+1);
		l=strlen(s+1);
		hsh=0;
		for(int j=1;j<=l;j++)
			hsh=hsh*base+s[i];
		a[i][2]=hsh;
	}
	mi[0]=1;
	for(int i=1;i<=2e5;i++)
		mi[i]=mi[i-1]*base;
	while(q--){
		scanf("%s",s+1);
		scanf("%s",ss+1);
		int l=strlen(s+1);
		for(int i=1;i<=l;i++){
			ha[i]=ha[i-1]*base+s[i];
		}
		hsh=0;int ans=0;
		for(int i=1;i<=l;i++)
			hsh=hsh*base+ss[i];
		for(int i=1;i<=n;i++){
			for(int j=1;j+a[i][3]-1<=l;j++)
			if(ha[j+a[i][3]-1]-mi[a[i][3]]*a[i][1]==ha[j-1]){
				t=ha[l]-mi[a[i][3]]*a[i][1]+mi[a[i][3]]*a[i][2];
				if(t==hsh)ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
