#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[1005],t[1005],a,b;
struct chge{
	string s,t;
	int bp,Bp;
}e[200005];
vector<vector<int> > anss;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
		for(int i=1;i<=n;i++){
			cin>>s[i]>>t[i];
		}for(int i=1;i<=q;i++){
			cin>>a>>b;
			int a1=a.size(),b1=b.size(),ans=0;
			if(a1!=b1){cout<<"0\n";continue;}
			for(int j=1;j<=n;j++){
				int s1=s[j].size();
				if(s1>a1) continue;
				for(int k=0;k+s1<=a1;k++){
					bool kk=0;
					for(int l=0;l<s1;l++){
						if(a[k+l]!=s[j][l]||b[k+l]!=t[j][l]){kk=1;continue;}
					}
					if(!kk){kk=1;
						for(int ty=k+s1;ty<a1;ty++){
							if(a[ty]!=b[ty]){kk=0;break;}
						}
						ans+=kk;break;
					}
				}
			}
			cout<<ans<<"\n";
		}
	return 0;
}/*
暴力找->哈希比较 
n个数 q个询问 共L长度
哈希太久远了了没把握 
*/
