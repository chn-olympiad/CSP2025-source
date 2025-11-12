#include<bits/stdc++.h>
using namespace std;
const int N=510;
int n,q;
string s1,s2,t1,t2;
map<string,string>m;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		m[s1]=s2;
	}
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		int p=t1.size(),ans=0;
		for(int j=1;j<=p;j++){
			for(int l=0,r=j-1;r<p;l++,r++){
				int f=0;
				for(int k=0;k<l;k++)if(t1[k]!=t2[k]){f=1;break;}
				for(int k=r+1;k<p;k++)if(t1[k]!=t2[k]){f=1;break;}
				if(f)continue;
				string g1,g2;
				for(int k=l;k<=r;k++)g1+=t1[k],g2+=t2[k];
				if(m[g1]==g2)ans++;
			} 
		}
		printf("%d\n",ans);
	}
	return 0; 
}