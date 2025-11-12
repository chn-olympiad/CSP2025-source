#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q,sn[N],tn[2],c;
string s[N][2],t[2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		s[i][0].push_back(' ');
		s[i][1].push_back(' ');
		while(c<'a'||c>'z')c=getchar();
		while(c>='a'&&c<='z')s[i][0].push_back(c),++sn[i],c=getchar();
		while(c<'a'||c>'z')c=getchar();
		for(int j=1;j<=sn[i];j++)s[i][1].push_back(c),c=getchar();
	}
	while(q--){
		int cnt=0,Begin=0,End=0;tn[0]=tn[1]=0;
		t[0].clear(),t[1].clear();
		t[0].push_back(' ');
		t[1].push_back(' ');
		while(c<'a'||c>'z')c=getchar();
		while(c>='a'&&c<='z')t[0].push_back(c),++tn[0],c=getchar();
		while(c<'a'||c>'z')c=getchar();
		while(c>='a'&&c<='z')t[1].push_back(c),++tn[1],c=getchar();
		if(tn[0]!=tn[1]){puts("0");continue;}
		int Tn=tn[0];
		for(int i=1;i<=Tn;i++)if(t[0][i]!=t[1][i]){Begin=i;break;}
		for(int i=Tn;i>=1;i--)if(t[0][i]!=t[1][i]){ End =i;break;}
		for(int i=1;i<=n;i++){
			int Finish=min(Begin,Tn-sn[i]+1);bool rpp=0;
			for(int j=max(1,End-sn[i]+1);j<=Finish;j++){
				for(int k=1;k<=sn[i];k++){
					if(t[0][j+k-1]==s[i][0][k]&&t[1][j+k-1]==s[i][1][k]){
						if(k==sn[i])cnt++,rpp=1;
					}else break;
				}if(rpp==1)break;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
