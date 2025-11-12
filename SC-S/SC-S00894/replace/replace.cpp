#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
ull ha0[200005],ha1[200005],h1[1000005],h2[1000005],p[1000005],k=13331,ff[1000005];
map<ull,int>	mp;
map<int,int>	to[400005];
int n,q,num,ans,sum;
char s[3][1000005],t1[1000005],t2[1000005];
vector<char>	ss[3][200005];
ull Hash(char st[]){
	ull t=0;
	int len=strlen(st);
	for(int i=0;i<len;i++){
		t=t*k+(ull)st[i];
	}
	return t;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	p[0]=1;
	for(int i=1;i<=1000000;i++)	p[i]=p[i-1]*k;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s %s",s[0],s[1]);
		int len=strlen(s[0]);
		ff[len]=1;
		sum+=len;
//		s[0][i].push_back('0');
//		for(int j=0;j<len;j++)	ss[0][i].push_back(s[0][j]),ss[1][i].push_back(s[1][j]);
//		s[0][i].push_back('0');
		ha0[i]=Hash(s[0]);
		ha1[i]=Hash(s[1]);
		if(!mp[ha0[i]])	mp[ha0[i]]=++num;
		if(!mp[ha1[i]])	mp[ha1[i]]=++num;
	}
//	printf("%d ",num);
	for(int i=1;i<=n;i++)
		to[mp[ha0[i]]][mp[ha1[i]]]=1;
	for(int i=1;i<=q;i++){
		scanf("%s %s",t1+1,t2+1);
//		printf("%s %s\n",t1+1,t2+1);
		int l1=strlen(t1+1),l2=strlen(t2+1);
		if(l1!=l2)	printf("0\n");
		else{
			ans=0;
			int l=0,r=0;
			for(int j=1;j<=l1;j++){
				if(t1[j]!=t2[j]){
					if(!l)	r=l=j;
					else	r=j;
				}
			}
			for(int j=1;j<=l1;j++){
				h1[j]=h1[j-1]*k+(ull)t1[j];
				h2[j]=h2[j-1]*k+(ull)t2[j];
			}
			int len=r-l+1;
//			printf("%d %d %d ",l,r,len);
			for(;len<=l1;len++){
				if(!ff[len])	continue;
				for(int j=max(1,r-len+1);j<=min(l,l1-len+1);j++){
//					printf("%d %d %d %d %d\n",max(1,r-len+1),min(l,l1-len+1),j,j+len-1,len);
					ull t=h1[j+len-1]-h1[j-1]*p[len];
					ull tt=h2[j+len-1]-h2[j-1]*p[len];
					if(mp.find(t)==mp.end() || mp.find(tt)==mp.end())	continue;
					if(to[mp[t]].find(mp[tt])!=to[mp[t]].end())	ans++;
				}
			}
			printf("%d\n",ans);
		}
	}
}