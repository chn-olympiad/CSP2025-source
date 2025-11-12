#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q,cnt;
string s[N][2],t[2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++)
		cin>>s[i][0]>>s[i][1];
	while(q--){
		cnt=0;
		cin>>t[0]>>t[1];
		for(int i=1;i<=n;i++){
			int l=s[i][0].size(),len=t[0].size();
			for(int j=0;j+l-1<len;j++){
				if(t[0].substr(0,j)==t[1].substr(0,j)&&t[0].substr(j+l,len-j-l)==t[1].substr(j+l,len-j-l)){
					if(t[0].substr(j,l)==s[i][0]&&t[1].substr(j,l)==s[i][1])
						cnt++;
				}	
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
