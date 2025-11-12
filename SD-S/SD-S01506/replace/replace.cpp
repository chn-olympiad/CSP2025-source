#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#define N 200010
using namespace std;
long long n,q;
string s1[N],s2[N];
long long speacial=0,sbcnt=0,sflag;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		long long cnt=0;
		for(int i=1;i<=n;++i){
			long long k=-1;
			while(t1.find(s1[i],k+1)!=-1){
				k=t1.find(s1[i],k+1);
				if(t1.substr(0,k)+s2[i]+t1.substr(k+s1[i].size())==t2){
					++cnt;
				}
			}
		}
		cout<<cnt<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
/*
*/
