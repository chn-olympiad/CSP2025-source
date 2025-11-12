#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pss pair<string,string>
const int N = 1e5+5;
int n,q;
string s1[N],s2[N];
pss t;
inline bool cmp(string A,string B){
	if(A.size()!=B.size())return 0;
	for(int i=0;i<A.size();i++){
		if(A[i]!=B[i])return 0;
	}
	return 1;
}
inline int has(string A,string B){
	if(A.size()<B.size())return 0;
	for(int i=0;i<A.size();i++){
		if(A[i]==B[0]){
			int o=0;
			for(int j=0;j<B.size();j++){
				if(A[i+j]!=B[j]){
					o=1;
					break;
				}
			}
			if(o==0){
				return 1;
			}
		}
	}
	return 0;
}
inline vector<int> hass(string A,string B){
	vector<int>ans;
	for(int i=0;i<A.size();i++){
		if(A[i]==B[0]){
			int o=0;
			for(int j=0;j<B.size();j++){
				if(A[i+j]!=B[j]){
					o=1;
					break;
				}
			}
			if(o==0){
				ans.push_back(i);
			}
		}
	}
	return ans;
}
inline string replace(int x,string A,string B,string C){
	for(int j=0;j<C.size();j++){
		A[j+x]=C[j];
	}
	return A;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		cin>>t.first>>t.second;
		int sum=0;
		for(int i=1;i<=n;i++){
			if(has(t.first,s1[i])){
//				cout<<"Has:"<<has(t.first,s1[i])<<"\n";
				vector<int>x=hass(t.first,s1[i]);
				for(int k=0;k<x.size();k++){
					string s=replace(x[k],t.first,s1[i],s2[i]);
//					cout<<"S:"<<s<<"\n"; 
					if(cmp(s,t.second)){
						sum++;
					}
				}
			}
		}
		printf("%d\n",sum);
	}
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

3 4
a b
b c
c d
aa bb
aa b
a c
b a



*/
