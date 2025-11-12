#include <bits/stdc++.h>
using namespace std;
int n,q;
char a1[1005][2005],a2[1005][2005];
int len[1005];
char s1[2005],s2[2005];
int l,r;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>a1[i]>>a2[i];
		len[i]=strlen(a1[i]);
	}
	while(q>0){
		q--;
		int ans=0;
		cin>>s1>>s2;
		int ls=strlen(s1);
		for(int i=0;i<ls;i++){
			if(s1[i]!=s2[i]){
				l=i;
				break;
			}
		}
		for(int i=ls-1;i>=0;i--){
			if(s1[i]!=s2[i]){
				r=i;
				break;
			}
		}
		for(int i=1;i<=n;i++){
			if(r-l+1>len[i])continue;
			int z=len[i]-(r-l+1);
			for(int j=l-z;j<=l;j++){
				int nl=-1;
				bool ok=1;
				while(nl<len[i]-1){
					nl++;
					if(a1[i][nl]!=s1[j+nl]||a2[i][nl]!=s2[j+nl]){
						ok=0;
						break;
					}
				}
				if(ok)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
