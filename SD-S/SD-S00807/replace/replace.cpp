#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,m;
string s1[N+5],s2[N+5];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while (m--){
		long long ans=0;
		string x,y;
		cin>>x>>y;
		for (int i=0;i<x.size();i++){
			for (int j=1;j<=n;j++){
				if (x.size()-i<s1[j].size()){
					continue;
				}
				string t=x.substr(i,s1[j].size());
//				cout<<i<<" "<<j<<" "<<t<<endl;
				if (s1[j]==t){
					string t_=x.substr(0,i)+s2[j]+x.substr(i+s1[j].size(),x.size()-(i+s1[j].size())+1);
					ans+=(y.compare(t_)==0);
//					cout<<"(*&^"<<" "<<t_<<" "<<y.compare(t_)<<endl;
				}
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
