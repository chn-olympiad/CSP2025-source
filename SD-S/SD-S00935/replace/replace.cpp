#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int N=1005,L=2048;
int n,q,samef[N],sameb[N],samesf[N],samesb[N];
long long int ans;
char s[N][2][L],t[N][2][L];
int lens[N],lent[N];

void repl(int x,int y){
//	char *p=t[x][0];
//	while(true){
//		char *now=strstr(p,s[y][0]);
//		if(!now)
//			break;
//		
//		
//		
//		p=now+1;
//	}
//	fprintf(stderr,"parsing %d %d\n",x,y);
	if(lens[y]-samesf[y]-samesb[y]+samef[x]+sameb[x]!=lent[x])
		return;
//	fprintf(stderr,"lives\n",x,y);
	char *now=strstr(t[x][0],s[y][0]);
	if(now){
//		fprintf(stderr,"lives %s %d %d %d %d\n",now,samef[x],sameb[x],now-t[x][0]+samesf[y],samef[x]);
		if(now-t[x][0]+samesf[y]==samef[x]){
			for(int i=samef[x],j=samesf[y];i<lent[x]-sameb[x];i++,j++)
				if(s[y][1][j]!=t[x][1][i])
					return;
			ans+=1;
//			fprintf(stderr,"vic!!!!\n");
		}
	}
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++){
		for(int j=0;j<2;j++)
			scanf("%s",s[i][j]);
		lens[i]=strlen(s[i][0]);
		for(int j=0;j<lens[i] && s[i][0][j]==s[i][1][j];j++)
			samesf[i]++;
		for(int j=lens[i]-1;j>=0 && s[i][0][j]==s[i][1][j];j--)
			samesb[i]++;
	}
	for(int i=0;i<q;i++){
		for(int j=0;j<2;j++)
			scanf("%s",t[i][j]);
		lent[i]=strlen(t[i][0]);
		for(int j=0;j<lent[i] && t[i][0][j]==t[i][1][j];j++)
			samef[i]++;
		for(int j=lent[i]-1;j>=0 && t[i][0][j]==t[i][1][j];j--)
			sameb[i]++;
	}
	
	for(int x=0;x<q;x++){
		ans=0;
		for(int y=0;y<n;y++)
			repl(x,y);
		printf("%d\n",ans);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

