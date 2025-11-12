#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
string s1[200005],s2[200005];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	for(int i=1;i<=q;i++){
		int sum=0;
		string t1,t2;
		cin>>t1>>t2;
		for(int j=1;j<=n;j++)
			for(int i=0;i<t1.size();i++){
				if(t1[i]==s1[j][0]){
					int flag=1,flagg=1;
					for(int k=1;k<s1[j].size();k++)
						if(t1[i+k]!=s1[j][k]){
							flag=0;
							break;
						}
					if(flag){
						for(int k=0;k<i;k++)
							if(t1[k]!=t2[k]){
								flagg=0;
								break;
							}
						if(flagg)
							for(int k=i;k<i+s2[j].size();k++){
								if(t2[k]!=s2[j][k-i]){
									flagg=0;
									break;
								}
							}
						if(flagg){
							for(int k=t2.size();k>=i+s2[j].size();k--)
								if(t1[k]!=t2[k]){
									flagg=0;
									break;
								}
						}
						sum+=flagg;	
					}
				}
			}
		printf("%lld\n",sum);
	}
	return 0;
}