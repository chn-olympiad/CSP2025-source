#include<bits/stdc++.h>
using namespace std;
map<string,string> mp;
long long ans[5000005];
int vis1[5000005],vis2[5000005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		mp[s1]=s2;
	}
	while(q--){
		memset(vis1,0,sizeof(vis1));
		memset(vis2,0,sizeof(vis2));
		memset(ans,0,sizeof(ans));
		string s1,s2;
		cin>>s1>>s2;
		for(int i=0;i<s1.size();i++){
			if(s1[i]!=s2[i]){
				vis1[i]=1;
			}
		}
		for(int i=1;i<=s1.size();i++){
			for(int j=0;j+i-1<s1.size();j++){
				if(j){
					ans[j]=max(ans[j],ans[j-1]);
				}
				string lin=s1.substr(j,i);
				while(mp[lin]!=""){
					lin=mp[lin];
				}
				string lin1=s2.substr(j,i);
				if(lin==lin1){
					if(j==0){
						ans[j]++;
					}
					else{
						ans[j+i-1]+=ans[j-1];
					}
					vis2[j]++;
					vis2[j+i]--;
				}
			}
		}
		for(int i=1;i<s1.size();i++){
			ans[i]=max(ans[i-1],ans[i]);
		}
		for(int i=1;i<s1.size();i++){
			vis2[i]+=vis2[i-1];
		}
		int flag=1;
		for(int i=0;i<s1.size();i++){
			if(vis1[i]&&!vis2[i]){
				flag=0;
			}
		}
		if(flag){
			printf("%lld\n",ans[s1.size()-1]);
		}
		else{
			printf("0\n");
		}
	}
	return 0;
} 
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
