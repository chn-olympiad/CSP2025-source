#include<bits/stdc++.h>
using namespace std;
char s1[5000009],s2[5000009];
string a1[200009],a2[200009];
int sz1[200009];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s",s1);
		scanf("%s",s2);
		a1[i]=s1;
		a2[i]=s2;
		sz1[i]=strlen(s1);
	}
	while(q--){
		scanf("%s",s1);
		scanf("%s",s2);
		string s=s1,c=s2,sc=s1;
		long long ans=0;
		for(int i=1;i<=n;i++){
//			printf("%s\n%s\n",a1[i].c_str());
			int l=0;
			int r=s.find(a1[i],l);
			while(r!=-1){
				for(int j=r;j<=r+sz1[i]-1;j++){
					s[j]=a2[i][j-r];
				}
				if(s==c){
					ans++;
				}
				s=sc;
				l=r+1;
				r=s.find(a1[i],l);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
