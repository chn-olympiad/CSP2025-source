#include<bits/stdc++.h>
using namespace std;
int n,q;
string sa[10005],sb[10005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>sa[i]>>sb[i];
	}
//	if(q==1){
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		int cnt=0;
		for(int i=1;i<=n;i++){
			string ssa=sa[i];
			string ssb=sb[i];
//			cout<<ssa<<" "<<ssb<<endl;
			for(int j=0;j<s1.size()-ssa.size()+1;j++){
				string k,pa,pb;
				k=s1.substr(j,ssa.size());
				pa=s1.substr(0,j);
				pb=s1.substr(j+ssa.size(),s1.size()-(j+ssa.size()));
				if(k==ssa&&pa+ssb+pb==s2){
//					cout<<pa<<" "<<k<<" "<<pb<<endl;
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
}
//4 2
//xabcx xadex
//ab cd
//bc de
//aa bb
//xabcx xadex
//aaaa bbbb
//3 4
//a b
//b c
//c d
//aa bb
//aa b
//a c
//b a
