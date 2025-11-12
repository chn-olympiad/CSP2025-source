#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
string s[N][3],t[N][3];
int vis=0,ans=0;
int n,q;
string change;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)cin>>s[i][1]>>s[i][2];
	for(int i=1;i<=q;i++){
		ans=0;
		cin>>t[i][1]>>t[i][2];
		if(t[i][1].length()!=t[i][2].length()){
			printf("0\n");
			continue;
		}
		for(int j=1;j<=n;j++){
			vis=0;
			int len=s[j][1].length();
			int cnt=0;
			int x=-1;
			for(int k=0;k<=t[i][1].length()-1;k++){
				if(s[j][1][cnt]==t[i][1][k]){
					cnt++;
					if(x==-1)x=k;
					if(cnt==len){
						vis=1;
						break;
					}
					continue;
				}
				cnt=0;
				x=-1;
			}
			if(x!=-1){
				change=t[i][1];
				for(int k=x;k<=x+len-1;k++){
					change[k]=s[j][2][k-x];
				}
				for(int k=0;k<=t[i][1].length()-1;k++){
					if(change[k]!=t[i][2][k]){
						vis=0;
						break;
					}
				} 
			} 
			if(vis==1)ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}