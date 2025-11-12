#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
map<string,string> mp;
string s1,s2,t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++){
		cin>>s1>>s2;
		mp[s1]=s2;
	}
	while(q--){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			printf("0\n");
			continue;
		}
        ans=0;
		for(auto it:mp){
			s1=it.first;
			s2=it.second;
			for(int i=0;i<t1.size();i++){
				bool flag=0;
				for(int j=0;j<i;j++){
                    if(t1[j]!=t2[j]){
                        flag=1;break;
                    }
				}
				if(flag) continue;

				for(int j=0;i+j<n&&j<s1.size();j++){
					if((s1[j]!=t1[i+j]||s2[j]!=t2[i+j])){
						flag=1;break;
					}
				}
				if(flag) continue;

                for(int j=i+(int)s1.size();j<t1.size();j++){
                    if(t1[j]!=t2[j]){
                        flag=1;break;
                    }
                }
                if(!flag) ans++;
			}
 		}
		printf("%d\n",ans);
	}
	return 0;
}
