#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=2e5+5;
int n,q,len[2][N];
vector<char> s[2][N];
char t1[N],t2[N];
void read(int x,int id){
	s[x][id].push_back('0');
	char c=getchar();
	while(c>'z'||c<'a') c=getchar();
	while(c<='z'&&c>='a'){
		s[x][id].push_back(c);
		c=getchar();
	}
	len[x][id]=s[x][id].size()-1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		read(0,i);
		read(1,i);
	}
	while(q--){
		ll ans=0;
		scanf(" %s %s",t1+1,t2+1);
		int len1=strlen(t1+1),len2=strlen(t2+1),head=0,end=0;
		if(len1!=len2){
			printf("0\n");
			continue;
		}
		for(int i=len1;i>=1;i--){
			if(t1[i]!=t2[i]){
				end=i;
				break;
			}
		}
		for(int i=1;i<=len1;i++){
			if(t1[i]!=t2[i]){
				head=i;
				break;
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=max(1,end-len[0][k]+1);i<=head;i++){
				bool flag=1;
				for(int j=1;j<=len[0][k];j++){
					if(t1[i+j-1]!=s[0][k][j]||t2[i+j-1]!=s[1][k][j]){
						flag=0;
						break;
					}
				}
				if(flag){
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
