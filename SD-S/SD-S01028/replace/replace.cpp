#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
string s1[N],s2[N],t1,t2;
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	while(q--){
		cin>>t1>>t2;
		int l,r,cnt=0;
		for(int j=1;j<=n;j++){
			l=0;r=0;
			while(r<t1.size()){
				if(t1[r]!=s1[j][r-l]) l=++r;
				else if(r-l>=s1[j].size()-1){
					char se[N]={'\0'};
					cout<<se;
					for(int i=0;i<l;i++) se[i]=t1[i];
					for(int i=l;i<r;i++) se[i]=s2[j][i];
					for(int i=r;i<t1.size();i++) se[i]=t1[i];
					for(int i=0;i<t2.size();i++){
						cout<<se[i];
						if(t2[i]!=se[i]){
							l=++r;
							break;
						}
					}
					if(r-l!=0) cnt++,l=++r;
				}
				else r++;
			}
			cout<<'\n';
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
