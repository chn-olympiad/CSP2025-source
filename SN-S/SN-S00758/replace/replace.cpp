#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
string s1,s2,word[200005][5];
map <int,int> b[500005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>word[i][1]>>word[i][2];
		int t1,t2;
		t1=word[i][1].find('b');
		t2=word[i][2].find('b');
		b[t1][t1-t2]++;
	}
	for(int i=1;i<=m;i++){
		cin>>s1>>s2;
		ans=0;
		int t1,t2;
		t1=s1.find('b');
		t2=s2.find('b');
		for(int i=0;i<=t1;i++)
			ans+=b[i][t1-t2];
		cout<<ans<<endl;
	}
 	return 0;
}
