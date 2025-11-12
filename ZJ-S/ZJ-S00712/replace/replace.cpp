#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
const int N=5*1e6+5,M=2*1e5+5;
string s[M][3],s1,s2;
int n,T,le[M],len;
bool pd(int k,int h,int t){
	if(le[k]<t-h+1||le[k]>len) return 0;
	for(int i=0;i<le[k]-(t-h);i++){
		int l=i,r=i+t-h,j,jj;
		for(j=l,jj=h;j<=r&&jj<=t;j++,jj++)if(s[k][1][j]!=s1[jj]||s[k][2][j]!=s2[jj])break;
		if(j!=r+1)continue;
		int l1=h,r1=t;
		do{l--;l1--;}while(l>=0&&s[k][1][l]==s1[l1]&&s[k][2][l]==s2[l1]);
		if(l>=0)continue;
		do{r++;r1++;}while(r<le[k]&&s[k][1][r]==s1[r1]&&s[k][2][r]==s2[r1]);
		if(r==le[k])return 1;
	}
	return 0;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&T);
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		le[i]=s[i][1].size();
	}
	while(T--){
		cin>>s1>>s2;
		len=s1.size();
		if(len!=s2.size()){cout<<0<<endl;continue;}
		int h=-1,t=-1;
		for(int i=0;i<len;i++)if(s1[i]!=s2[i]){
			t=i;
			if(h==-1)h=i;
		}
		if(t==-1){cout<<0<<endl;continue;}
		int ans=0;
		for(int i=1;i<=n;i++)if(pd(i,h,t))ans++;
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}