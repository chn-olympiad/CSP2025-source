// 暴力解决询问 O(L1 * L2)
// (1~5) = 25pts
#include<bits/stdc++.h>
using namespace std;
int read(){
	int x;
	cin>>x;
	return x;
}
const int N=2e5+10;
string s1[N],s2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr); 
	int n=read(),Q=read();
	for(int i=1;i<=n;++i)
		cin>>s1[i]>>s2[i];
	if(n>1000){
		map<int,int>mp;
		for(int i=1;i<=n;++i){
			int p1=s1[i].find('b');
			int p2=s2[i].find('b');
			++mp[p1-p2];
		}
		while(Q--){
			string t1,t2;
			cin>>t1>>t2;
			int p1=t1.find('b');
			int p2=t2.find('b');
			int res=mp[p1-p2];
			printf("%d\n",res);
		}
		return 0;
	}
	while(Q--){
		string t1,t2;
		cin>>t1>>t2;
		int cnt=0;
		for(int i=1;i<=n;++i){
			int p=t1.find(s1[i]);
			if(p>=0){
				for(int j=0;j<(int)s1[i].size();++j)
					t1[p+j]=s2[i][j];
				if(t1==t2)
					++cnt;
				for(int j=0;j<(int)s1[i].size();++j)
					t1[p+j]=s1[i][j];
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
/*

Input #1:

4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

Output #1:

2
0

Input #2:

3 4
a b
b c
c d
aa bb
aa b
a c
b a

Output #2:

0
0
0
0

My Input #1:

4 2
aaab baaa
aaba abaa
abaa aaab
baaa aaba
aabaa aaaba
aaaab abaaa

My Output #1:

0
1

My Input #1:

8 3
aaab baaa
aaba abaa
abaa aaab
baaa aaba
abaa aaba
aaba aaba
aaab abaa
aabaa abaaa
aabaaa abaaaa
aabaa aaaba
aaaab abaaa

My Output #1:

2
1
1

*/
