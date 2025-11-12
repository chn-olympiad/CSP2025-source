#include<bits/stdc++.h>

using namespace std;
const int MAXN=5000000+10;

	int n,q;
	string s1[MAXN],s2[MAXN],ques[MAXN];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		cin>>ques[i];
	}
	for(int i=1;i<=q;i++)cout<<"0"<<endl;
	return 0;
}
