#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200005][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s[i][0]>>s[i][1];
	while(q--){
		int ans=0;
		string S,S2;cin>>S;
		cin>>S2;
//		cout<<S<<'\n';
		for(int i=0;S[i];i++){
			for(int j=1;j<=n;j++){
				if(s[j][0].size()+i-1>S.size()) continue;
//				printf("%d %d %d\n",q,i,j);
				bool f=1;
				for(int k=0;s[j][0][k];k++){
					if(S[i+k]!=s[j][0][k]){
//						printf("%c %c\n",S[i+k],s[j][0][k]);
						f=0;
						break;
					}
				}
				if(f){
//					printf("%d %d\n",j,q);
					string s2="";
					if(i) for(int k=0;k<i;k++) s2+=S[k];
					for(int k=0;s[j][1][k];k++) s2+=s[j][1][k];
					for(int k=s[j][1].size()+i;S[k];k++) s2+=S[k];
					if(S2==s2) ans++;
//					cout<<s2<<'\n';
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
