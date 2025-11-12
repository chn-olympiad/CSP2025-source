#include <cstdio>
#include <cstring>
#include <algorithm>

const int maxn=1005,maxs=2005;
char str1[maxn][maxs],str2[maxn][maxs];
char s1[maxs],s2[maxs];
char tmp[maxs+maxs];

int main(){
	//freopen("replace.in","r",stdin);
	//freopen("replace.out","w",stdout);
	
	
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s",&str1[i][1]);
		scanf("%s",&str2[i][1]);
	}
	while(q--){
		scanf("%s%s",&s1[1],&s2[1]);
		int len1=strlen(&s1[1]),len2=strlen(&s2[1]);
		
		int ans=0;
		for(int i=1;i<=n;i++){
			int len=strlen(&str1[i][1]);
			for(int l=1;l<=len1;l++){
				for(int r=l;r<=len1;r++){
					bool f=true;
					if(r-l+1!=len) f=false;
					for(int j=l,k=1;j<=r;j++,k++){
						if(str1[i][k]!=s1[j]) f=false;
					}
					if(f){
						bool flag=true;
						for(int k=1;k<=len1;k++){
							if(l<=k&&k<=r){
								if(str2[i][k-l+1]!=s2[k-l+1])
									f=false;
							}else if(s1[k]!=s2[k]) f=false;
						}
						if(flag) ans++;
					}
				}
			}
			
		}
		printf("%d\n",ans);
		
		int t=std::max(len1,len2);
		for(int i=1;i<=t;i++) s1[i]=0,s2[i]=0,tmp[i]=0;
	}
	return 0;
}
