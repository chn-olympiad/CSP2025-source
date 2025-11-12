#include<bits/stdc++.h>
using namespace std;
const int N=1e6+15;
int n,m,k,flag[15],tot2,vis[15];
string s1[N],s2[N],ss1,ss2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		for(int j=0;j<s1[i].size();j++){
			if(s1[i][j]==s2[i][j]){
				s1[i].erase(j,1);
				s2[i].erase(j,1);
				j--;
			}
		}
	}
	while(m--){
		int cnt=0;
		cin>>ss1>>ss2;
		int flag1=-1,flag2;
		for(int i=0;i<ss1.size();i++){
			if(ss1[i]!=ss2[i]&&flag1==-1){
				flag1=i;
			}
			if(ss1[i]!=ss2[i]) flag2=i;
		}
		string st=ss1.substr(flag1,flag2-flag1+1),st1=ss2.substr(flag1,flag2-flag1+1);
		for(int i=1;i<=n;i++){
			if(s1[i]==st&&s2[i]==st1){
				cnt++;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
