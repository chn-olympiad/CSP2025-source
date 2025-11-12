//long long
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string s1[N],s2[N];
int pre[5000005];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i]; 
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<"0\n";
			continue;
		}
		int ans=0;
		for(int o=1;o<=n;o++){
			int j=0,len=s1[o].size()-1;
			if(len>t1.size()-1)continue;
			pre[0]=-1;
			for(int i=2;i<=len;i++){
				while(j!=-1&&s1[o][j+1]!=s1[o][i])j=pre[j];
				if(s1[o][j+1]==s1[o][i])j++;
				pre[i]=j;
			}
			j=0;
			for(int i=0;i<t1.size();i++){
				while(j!=-1&&s1[o][j+1]!=t1[i])j=pre[j];
				if(s1[o][j+1]==t1[i])j++;
				if(j==len){
					string t=t1;
					for(int id=i-len;id<=i;id++)t[id]=s2[o][id-(i-len)];
					if(t==t2){
						ans++;
						break;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
设字符串t1和t2可以替换得来，则t1=x+y+z,t2=x+y'+z
因为x=x,y!=y,z=z且只能替换一处，所以所谓的"字串y的位置不同"是不可能做到的 

4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/ 
