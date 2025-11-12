#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
map< pair<ull,ull> ,int>dif;
const int N=2e5+5,M=5e6+5,B=31;
int n,q,num_dif,len1[N],len2[N],vec0;
char st[2][M];
ull sam1[N],sam2[N],q1[M],q2[M];
vector<int>d_s[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s%s",st[0],st[1]);
		int l=1,r=strlen(st[0]),m=r;
		while(st[0][l-1]==st[1][l-1])l++;
		while(st[0][r-1]==st[1][r-1])r--;
		if(l>r){
			vec0++;
			continue;
		}
		ull t=0,T=0;
		for(int j=l;j<=r;j++)t=t*B+(st[0][j-1]-96),T=T*B+(st[1][j-1]-96);
		auto h=make_pair(t,T);
		if(dif[h]==0)dif[h]=++num_dif;
		d_s[dif[h]].push_back(i);
		t=0;
		for(int j=l-1;j>=1;j--){
			t=t*B+(st[0][j-1]-96);
			len1[i]++;
		}
		sam1[i]=t;
		t=0;
		for(int j=r+1;j<=m;j++){
			t=t*B+(st[0][j-1]-96);
			len2[i]++;
		}
		sam2[i]=t;
	}
	while(q--){
		scanf("%s%s",st[0],st[1]);
		int m=strlen(st[0]);
		if(m!=strlen(st[1])){
			puts("0");
			continue;
		}
		int l=1,r=m;
		while(st[0][l-1]==st[1][l-1])l++;
		while(st[0][r-1]==st[1][r-1])r--;
		if(l>r){
			printf("%d\n",vec0);
			continue;
		}
		ull t=0,T=0;
		for(int j=l;j<=r;j++)t=t*B+(st[0][j-1]-96),T=T*B+(st[1][j-1]-96);
		int cnt=dif[make_pair(t,T)];
		if(cnt==0){
			puts("0");
			continue;
		}
		for(int j=l-1,o=1;j>=1;j--,o++){
			q1[o]=q1[o-1]*B+(st[0][j-1]-96);
		}
		for(int j=r+1,o=1;j<=m;j++,o++){
			q2[o]=q2[o-1]*B+(st[0][j-1]-96);
		}
		int res=0;
		for(int p:d_s[cnt]){
			if(l-1>=len1[p]&&m-r>=len2[p]&&q1[len1[p]]==sam1[p]&&q2[len2[p]]==sam2[p])res++;
		}
		printf("%d\n",res);
	}
	return 0;
}
