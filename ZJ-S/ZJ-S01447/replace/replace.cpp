#include<bits/stdc++.h>
using namespace std;
int n,q,l[200001],sums,slen[200001],r[200001],len,tl,tr,answer,S[200001];
string s[200001][3],tj1,tj2;
bool F=true;
void work(){
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		s[i][1]=" "+s[i][1];
		s[i][2]=" "+s[i][2];
		l[i]=0;
		slen[i]=s[i][1].size()-1;
		for(int j=1;j<=slen[i];j++){
			if(s[i][1][j]!=s[i][2][j]){
				if(l[i]==0) l[i]=j;
				r[i]=j;
			}
		}
	}
	while(q--){
		cin>>tj1>>tj2;
		if(tj1.size()!=tj2.size()){
			puts("0");
			continue;
		}
		len=tj1.size();
		tj1=" "+tj1;
		tj2=" "+tj2;
		tl=len+1,tr=1;
		for(int i=1;i<=len;i++){
			if(tj1[i]!=tj2[i]){
				if(tl==len+1) tl=i;
				tr=i;
			}
		}
		answer=0;
		for(int i=1;i<=n;i++){
			if(l[i]!=0&&tr-tl==r[i]-l[i]&&tl-(l[i]-1)>0&&tr+(slen[i]-r[i])<=len){
				if(tj1.substr(tl-l[i]+1,slen[i])==s[i][1].substr(1)&&tj2.substr(tl-l[i]+1,slen[i])==s[i][2].substr(1)){
					answer++;
				}
			}
		}
		cout<<answer;
		puts("");
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	work();
	return 0;
}
//27578
