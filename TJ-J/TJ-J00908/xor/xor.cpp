#include<cstdio>
long long int line[500010];
bool vis[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out ","w",stdout);
	int n,k,ans=0;
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&line[i]);
		line[i]^=line[i-1];
	}
	for(int i=1;i<=n;i++){
		int l=1;
		for(int j=i;j<=n;j++){

			bool flag=1;
			if((line[j]^line[l-1])==k){
				for(int g=l;g<=j;g++){
					if(vis[g]){
						flag=0;
						break;
					}
				}
				if(flag){
					ans++;
					for(int g=l;g<=j;g++){
						vis[g]=1;
					}					
				}
			}
			l++;
		}
	}
	printf("%d",ans);
	
	return 0;
} 
