#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string s1[1005],s2[1005],t1,t2;
int main(){
	freopen("replace1.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		ans=0;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			printf("0\n");
			continue;
		}
		for(int i=0;i<=t1.size();i++){
			for(int j=1;j<=n;j++){
				int p=0;
				for(int k=0;k<t1.size();k++){
					if(k<=i+s1[j].size()-1&&k>=i){
						if(s1[j][k-i]!=t1[k]||s2[j][k-i]!=t2[k]){
							p++;
							break;
						}
					}
					else{
						if(t1[k]!=t2[k]){
							p++;
							break;
						}
					}
				}
				if(p==0){
					ans++;
					continue;
				}
			}
		}
		printf("%d\n",ans);
	}
}

