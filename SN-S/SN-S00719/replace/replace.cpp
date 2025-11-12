#include <bits/stdc++.h>
using namespace std;
const int N=5e6+7;
typedef long long ll;
int n,q;
string s1[N],s2[N];
string t1[N],t2[N];
ll ans;

int main(){
	
	freopen("replace.in","r",stdin);//要改 
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	for(int i=1;i<=q;i++) cin>>t1[i]>>t2[i];
	
	for(int i=1;i<=q;i++){
		ans=0;
		
		int len1=t1[i].size();
		for(int j=0;j<len1;j++){
//			if(t1[i][j]==t2[i][j]) continue;
//			//不相等
			for(int z=1;z<=n;z++){//寻找 
				if(s1[z][0]==t1[i][j]&&s2[z][0]==t2[i][j]){
					ans++;
					int len2=s1[z].size();
					bool flag=true;
					for(int idx=1;idx<len2;idx++){
						if(s1[z][idx]!=t1[i][j]||s2[z][idx]!=t2[i][j]){
							flag=false;
							break;
						}
					}
					if(!flag) ans--;
					
				}
			}
			
		}
		cout<<ans<<endl;
	}
	
	return 0;
} 
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a

4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/ 
