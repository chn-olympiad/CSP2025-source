#include<bits/stdc++.h>
using namespace std;
string s[200005][3];
string h1[200005];
string thr[2005][2005];
int ans=0;
int changeb[2000005];
pair<int,pair<int,int> >cr[2000005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	if(n<=1000 && q<=1000 && q!=1){
		while(q--){
			string t1,t2;
			cin>>t1>>t2;
			string tmp1="";
			h1[t1.size()]="";
			ans=0;
			for(int i=t1.size()-1;i>=0;i--){
				h1[i]=h1[i+1]+t1[i];
			}
			for(int i=0;i<t1.size();i++){
				string tt="";
				for(int j=i;j<t1.size();j++){
					tt+=t1[j];
					thr[i][j]=tt;
				}
			}
			for(int i=0;i<t1.size();i++){
				for(int j=1;j<=n;j++){
					if(i+s[j][1].size()<=t1.size()){
						if(s[j][1]==thr[i][i+s[j][1].size()-1]){
							if(tmp1+s[j][2]+h1[i+s[j][1].size()]==t2)ans++;
						}
					}
				}
				tmp1+=t1[i];
			}
			printf("%d\n",ans);
		}	
	}
	else {
		for(int i=1;i<=n;i++){
			int b1=-1,b2=-1;
			for(int j=0;j<s[i][1].size();j++){
				if(s[i][1][j]=='b')b1=j;
				if(s[i][2][j]=='b')b2=j;
			}
			cr[i]=make_pair(b2-b1,make_pair(b1,s[i][1].size()-b2));
		}
		while(q--){
			string t1,t2;
			cin>>t1>>t2;
			int b1=-1,b2=-1,ans=0;
			for(int j=0;j<t1.size();j++){
				if(t1[j]=='b')b1=j;
				if(t2[j]=='b')b2=j;
			}
			for(int j=1;j<=n;j++){
				if(b2-b1==cr[j].first && b1>=cr[j].second.first && t1.size()-b2>=cr[j].second.first)ans++;
			}
			printf("%d\n",ans);
		}
	}
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
