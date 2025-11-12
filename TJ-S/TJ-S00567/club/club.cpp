#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
struct node{
	int id,c,mx,mn,id2;
};
node line[100010];
bool cmp(node a,node b){
	return	a.id<b.id||a.id==b.id&&a.c>b.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		memset(line,0,sizeof(line));
		int n,ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			int a1,a2,a3;
			scanf("%d %d %d",&a1,&a2,&a3);
			if(a1>a2&&a1>a3){
				line[i].mx=a1;
				line[i].id=1;
				if(a2>a3){
					line[i].mn=a2;
					line[i].id2=2;
				}
				else{
					line[i].mn=a3;
					line[i].id2=3;	
				}
			}
			else if(a2>a3){
				line[i].mx=a2;
				line[i].id=2;
				if(a1>a3){
					line[i].mn=a1;
					line[i].id2=1;
				}
				else{
					line[i].mn=a3;
					line[i].id2=3;	
				}
			}
			else{
				line[i].mx=a3;
				if(a2>a1){
					line[i].mn=a2;
					line[i].id2=2;
				}
				else{
					line[i].mn=a1;
					line[i].id2=1;	
				}
			}
			line[i].c=line[i].mx-line[i].mn;
		}
		sort(line+1,line+1+n,cmp);
		int cnt[4]={0,0,0,0};
		for(int i=1;i<=n;i++){
			if(cnt[line[i].id]<n/2){
				cnt[line[i].id]++;
				ans+=line[i].mx;
			}
			else{
				cnt[line[i].id2]++;
				ans+=line[i].mn;
			}
		}
		printf("%d\n",ans);
	}

	
	
	
	
	return 0;
}
