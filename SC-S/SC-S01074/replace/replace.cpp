#include<bits/stdc++.h>
using namespace std;
const int N =2e5+100;
string s1[N],s2[N];
string t1[N],t2[N];
int n,m;
int main (){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)	cin>>s1[i]>>s2[i];
	for(int i=0;i<m;i++){
		cin>>t1[i]>>t2[i];
		int sum=0;
		for(int j=0;j<n;j++){
			int f1=t1[i].find(s1[j]),f2=t2[i].find(s2[j]);
			//cout<<f1<<f2;
			if(f1==f2&&(f1!=-1)){
				string v1=t1[i],v2=t2[i];
				int len=s1[i].size();
				v1.erase(f1,len);
				v2.erase(f1,len);
				if(v1==v2)	sum++;
			}
		}
		cout<<sum<<endl;
	}
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