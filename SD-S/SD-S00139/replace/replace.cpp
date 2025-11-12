#include<bits/stdc++.h>
using namespace std;
const int mod1=1e9+7,mod2=1e9+9;
string s[200001][2],t[2];
int len[200001],sum1[200001][2],cnt1[5000001][2],p1[5000001]={1},sum2[200001][2],cnt2[5000001][2],p2[5000001]={1};
int main(){
	freopen("replace3.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,ans;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		len[i]=s[i][0].size();
		for(int j=0;j<len[i];j++){
			sum1[i][0]=(26ll*sum1[i][0]+s[i][0][j]-48)%mod1;
			sum1[i][1]=(26ll*sum1[i][1]+s[i][1][j]-48)%mod1;
			sum2[i][0]=(26ll*sum2[i][0]+s[i][0][j]-48)%mod2;
			sum2[i][1]=(26ll*sum2[i][1]+s[i][1][j]-48)%mod2;
		}
	}
	for(int i=1;i<=5e6;i++){
		p1[i]=26ll*p1[i-1]%mod1;
		p2[i]=26ll*p2[i-1]%mod2;
	}
	int ii=0;
	while(q--){
		ii++;
		ans=0;
		cin>>t[0]>>t[1];
		for(int i=1;i<=t[0].size();i++){
			cnt1[i][0]=(26ll*cnt1[i-1][0]+t[0][i-1]-48)%mod1;
			cnt1[i][1]=(26ll*cnt1[i-1][1]+t[1][i-1]-48)%mod1;
			cnt2[i][0]=(26ll*cnt2[i-1][0]+t[0][i-1]-48)%mod2;
			cnt2[i][1]=(26ll*cnt2[i-1][1]+t[1][i-1]-48)%mod2;
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j+len[i]<=t[0].size();j++){
				int x=t[0].size()-j-len[i];
				if(cnt1[j+len[i]][0]==(1ll*cnt1[j][0]*p1[len[i]]+sum1[i][0])%mod1 && (cnt1[t[0].size()][0]+1ll*p1[x]*sum1[i][1])%mod1==(cnt1[t[0].size()][1]+1ll*p1[x]*sum1[i][0])%mod1 && cnt2[j+len[i]][0]==(1ll*cnt2[j][0]*p2[len[i]]+sum2[i][0])%mod2 && (cnt2[t[0].size()][0]+1ll*p2[x]*sum2[i][1])%mod2==(cnt2[t[0].size()][1]+1ll*p2[x]*sum2[i][0])%mod2){
					ans++;
					break;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
