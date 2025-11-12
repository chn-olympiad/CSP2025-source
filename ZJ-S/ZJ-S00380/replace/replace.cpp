#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int mod1=998244353,mod2=1e9+7;
const int N=2e5+5;
int n,q;
string s1[N],s2[N],t1,t2,fi,la;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		int fi=0,la=0;
		if(t1.size()!=t2.size()){
			cout<<0<<"\n";
			continue;
		}
		bool f=false;
		for(int i=0;i<t1.size();i++){
			if(t1[i]!=t2[i]){
				if(!f){
					fi=i;
				}
				f=true;
				la=i;
			}
		}
		string sum1,sum2;
		for(int i=fi;i<=la;i++){
			sum1+=t1[i];
			sum2+=t2[i];
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(s1[i].find(sum1)<=2e9&&s2[i].find(sum2)<=2e9){
				cnt++;
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
