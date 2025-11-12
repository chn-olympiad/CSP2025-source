#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#define Max(a,b) (((a)>(b))?(a):(b))
#define Min(a,b) (((a)<(b))?(a):(b))
#define L(i,a,b) for(int i=(a);i<=(b);i++)
#define R(i,a,b) for(int i=(a);i>=(b);i--)
#define mymain iadsjkjifes
#define mycmp adsijoasiofj
using namespace std;
const int Mxn=5e2+10;
int n,q;
char s1[Mxn][Mxn],s2[Mxn][Mxn];
int sl[Mxn];
long long ans=0;
bool mycmp(char *s1,char *s2,int x,int y,int a){ 
	int t=a;
	L(i,x,y){
		if(s1[i]!=s2[a])return false;
		a++;
	}
	return true;
}
void mymain(){
	ans=0;
	char c1[Mxn],c2[Mxn];int cl;
	scanf("%s",c1);scanf("%s",c2);cl=strlen(c1);
//printf("c1:%s  ",c1);printf("c2:%s  \n",c2);
	L(k,1,n){
		L(i,0,cl-1){
			//printf("i=%d\n",i);
			if(i+sl[i]-1>cl-1)continue;
			if(mycmp(c1,c2,0,i-1,0)||i==0){//ÅÐ¶Ïx 
				//printf("1\n");
				if(mycmp(c1,c2,i+sl[i],cl-1,i+sl[i])||i+sl[i]==cl){//ÅÐ¶Ïz
					//printf(" 2\n");
					if(mycmp(s1[i],c1,0,sl[i]-1,i)&&mycmp(s2[i],c2,0,sl[i]-1,i)){
						//printf("  3\n");
						ans++;
					}
				}
			}
		}
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d\n",&n,&q);
	L(i,1,n){
		scanf("%s",s1[i]);
		scanf("%s",s2[i]);
		sl[i]=strlen(s1[i]);
	}
//L(i,1,n){printf("s1 LEN=%d: %s  ",sl[i],s1[i]);printf("s2 LEN=%d: %s\n",sl[i],s2[i]);}
	L(i,1,q){
		mymain();
	}
	
//char aa[Mxn]={"01"},bb[Mxn]={"101"};printf("%s",mycmp(aa,bb,0,1,0)?"true":"false");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
