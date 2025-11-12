#include<bits/stdc++.h>
using namespace std;
string s[200005][2],t[200005][2];
int fail[2005];
int cnt[2][2005];
int tot[2];
bool bb[2005];
void fd(string s,string t,int num){
	tot[num]=0;
	s=" "+s;t=" "+t;
	fail[1]=0;
	for (int i=2;i<t.size();i++){
		int q=fail[i-1];
		while (q!=0&&t[i]!=t[fail[q]+1])q=fail[q];
		if (t[i]==t[fail[q]+1])q++;
		fail[i]=q;
	}
	int r=0;
	for (int i=1;i<s.size();i++){
		while (r!=0&&t[r+1]!=s[i])r=fail[r];
		if (t[r+1]==s[i])r++;
		if (r==t.size()-1)cnt[num][++tot[num]]=i-1;
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	for (int i=1;i<=q;i++){
		cin>>t[i][0]>>t[i][1];
	}
	for (int i=1;i<=q;i++){
		int ans=0;
		if (t[i][1].size()!=t[i][0].size()){
			printf("0\n");
			continue;
		}
		int st=-1,en=t[i][0].size();
		while (t[i][0][st+1]==t[i][1][st+1])st++;
		while (t[i][0][en-1]==t[i][1][en-1])en--;
		for (int j=1;j<=n;j++){
			fd(t[i][0],s[j][0],0);
			fd(t[i][1],s[j][1],1);
			memset(bb,false,sizeof(bb));
			for (int k=1;k<=tot[0];k++)if (cnt[0][k]>=en-1&&cnt[0][k]-s[j][0].size()+1<=st+1)bb[cnt[0][k]]=true;
			for (int k=1;k<=tot[1];k++){
				if (bb[cnt[1][k]]==true)ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
