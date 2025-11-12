#include<bits/stdc++.h>
using namespace std;
int n,q;
string t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>t1>>t2;
	}
	while(q--){
		int cnt=0;
		string s1,s2;
		cin>>s1>>s2;
//		if(n<=100&&q<=100&&s1.size()<=200&&s2.size()<=200){
//			for(int i=1;i<=n;i++){
//				int x=t1[i].size();
//				for(int j=0;j+x-1<s1.size();j++){
//					if(s1.substr(0,j)==s2.substr(0,j)&&t2[i]==s2.substr(j,x)&&s1.substr(j+x-1,s1.size()-j-i+1)==s1.substr(j+x-1,s1.size()-j-i+1)){
//						cnt++;
//					}
//				}
//			}
//		}
		cout<<cnt<<"\n";//ÇáËÉ¹ýÑùÀý2 
	}
	return 0;
}

