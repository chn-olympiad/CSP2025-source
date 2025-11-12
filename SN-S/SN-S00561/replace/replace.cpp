#include <bits/stdc++.h>
using namespace std;
bool st;
int n,q;
string s1[200005],s2[200005];
string t1,t2;
unsigned long long hash_1[5000005],hash_2[5000005];
unsigned long long th1[200005];
unsigned long long th2[200005];
unsigned long long qp[5000005];
const int p=31;
bool ed;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
//    cout<<(&ed-&st)/1024.0/1024.0<<'\n';
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<(int)s1[i].size();j++){
			th1[i]=th1[i]*p+(s1[i][j]-'a'+1);
		}
		for(int j=0;j<(int)s2[i].size();j++){
			th2[i]=th2[i]*p+(s2[i][j]-'a'+1);
		}
	}
	qp[0]=1;
	for(int i=1;i<=n;i++){
		qp[i]=qp[i-1]*p;
	}
//	for(int i=1;i<=n;i++){
//		cout<<qp[i]<<" ";
//	}
//	cout<<'\n';
//    for(int i=1;i<=n;i++){
//    	cout<<th1[i]<<" "<<th2[i]<<'\n';
//	}
	while(q--){
		int ans=0;
		cin>>t1>>t2;
		t1=' '+t1,t2=' '+t2;
		if(t1.size()!=t2.size()){
			cout<<0<<'\n';
			continue;
		}
		int l=0,r=0,flag=0;
		for(int i=1;i<(int)t1.size();i++){
			if(t1[i]!=t2[i]){
				r=i;
				if(flag==0){
					l=i;
					flag=1;
				}
			}
		}
//		cout<<l<<" "<<r<<'\n';
		hash_1[0]=0,hash_2[0]=0;
		for(int i=1;i<(int)t1.size();i++){
			hash_1[i]=hash_1[i-1]*p+(t1[i]-'a'+1);
			hash_2[i]=hash_2[i-1]*p+(t2[i]-'a'+1);
		}
		for(int i=1;i<=l;i++){
			for(int j=1;j<=n;j++){
				if(i+(int)s1[j].size()-1>=r&&i+(int)s1[j].size()-1<(int)t1.size()){
					int pl=i+s1[j].size()-1;
					if(hash_1[pl]-hash_1[i-1]*qp[s1[j].size()]==th1[j]){
						if(hash_2[pl]-hash_2[i-1]*qp[s2[j].size()]==th2[j]){
//							cout<<i<<" "<<pl<<" "<<j<<'\n'; 
							ans++;
						}
					}
				}
			}
		}
		cout<<ans<<'\n';
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
*/
