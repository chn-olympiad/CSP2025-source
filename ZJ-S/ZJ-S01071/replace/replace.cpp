#include<bits/stdc++.h>
using namespace std;
int n,m;
string sa,sb;
struct node{
	string s1,s2;
}a[200001];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i].s1>>a[i].s2;
	for(int i=1;i<=m;i++){
		int cnt=0;
		cin>>sa>>sb;
		for(int k=1;k<=n;k++){
			if(sa.size()<a[k].s1.size()) continue;
			for(int j=0;j<=sa.size()-a[k].s1.size();j++){
				int len=a[k].s1.size();
				string sq=sa.substr(j,len),sh=sb.substr(j,len);
				if(sq==a[k].s1){
					int x=sa.size()-a[k].s1.size();
					string st=sa.substr(0,j),sw=sa.substr(j+len,x);
					string s=st+sh+sw;
					if(s==sb){
						cnt++;
						break;
					}
				}
			}	
		}
		cout<<cnt<<endl;
	}
	return 0;
}
