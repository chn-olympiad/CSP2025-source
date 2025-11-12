#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define I 100005
struct se{
	string s1,s2;
};
se mr[I],qe[I];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>mr[i].s1>>mr[i].s2;
	}
	for(int i=1;i<=q;i++){
		cin>>qe[i].s1>>qe[i].s2;
	}
	for(int i=1;i<=q;i++){
		int fangan=0;
		for(int j=1;j<=qe[i].s1.length();j++){
			for(int k=1;k<=n;k++){
				string zhchuan="";
				for(int l=1;l<=k;l++){
					zhchuan=zhchuan+qe[i].s1[l];
				}
				for(int l=1;l<=n;l++){
					if(zhchuan==mr[l].s1){
						zhchuan=mr[l].s2;
						break;
					} 
				}
				int z=0; 
				string xinchuan="";
				for(int l=1;l<=qe[i].s1.length();l++){
					if(l==k and l-k<=j){
						xinchuan+=zhchuan[z];
						z++;
						continue;
					}
					xinchuan+=qe[i].s1[l];
				}
				if(xinchuan==qe[i].s2) fangan++;
			}
			
		}
		cout<<fangan<<'\n';
	}
	return 0;
}
