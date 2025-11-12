#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=3100;
string s1[N],s2[N],t1,t2;
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		int ans=0;
		for(int j=1;j<=n;j++){
			int len=s1[j].size();
			for(int w=1;w<=t1.size()-len+1;w++){
				bool f=1;
				string ss=t1;
				for(int k=0;k<len;k++){
					if(s1[j][k]!=t1[w+k-1]){
						f=0;
						break;
					}
					else ss[w+k-1]=s2[j][k];
				}
				if(f){
				    if(ss==t2)ans++;				
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
