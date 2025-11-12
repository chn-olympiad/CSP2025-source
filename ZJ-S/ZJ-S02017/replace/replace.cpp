#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n,q,id1[N],id2[N];
string s1[N],s2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	if(n<=1000||q==1){
		while(q--){
			string sa,sb;
			cin>>sa>>sb;
			int m=sa.size(),m1=sb.size();
			if(m!=m1||sa==sb){
				printf("0\n");
				continue;
			}sa=' '+sa,sb=' '+sb;
			int l=1,r=m;
			while(l<=m&&sa[l]==sb[l])l++;
			while(r&&sa[r]==sb[r])r--;
			int ans=0;
			for(int i=1;i<=n;i++){
				int l1=s1[i].size();
				if(l1<r-l+1)continue;
				int ll=max(1,r-l1+1),rr=l;
				for(int j=ll;j<=rr;j++){
					string s3=sa.substr(j,l1),s4=sb.substr(j,l1);
					if(s3==s1[i]&&s4==s2[i])ans++;
				}
			}printf("%d\n",ans);
		}return 0;
	}for(int i=1;i<=n;i++)
		for(int j=1;j<s1[i].size();j++){
			if(s1[i][j]=='b')id1[i]=j;
			if(s2[i][j]=='b')id2[i]=j;
		}
	while(q--){
		string sa,sb;
		cin>>sa>>sb;
		int m=sa.size(),m1=sb.size();
		if(m!=m1||sa==sb){
			printf("0\n");
			continue;
		}sa=' '+sa,sb=' '+sb;
		int idx1,idx2;
		for(int i=1;i<=m;i++){
			if(sa[i]=='b')idx1=i;
			if(sb[i]=='b')idx2=i;
		}int ans=0;
		for(int i=1;i<=n;i++)if(id1[i]<=idx1&&s1[i].size()-id1[i]<=m-idx1&&id2[i]-id1[i]==idx2-idx1)ans++;
		printf("%d\n",ans);
	}return 0;
}
