#include<bits/stdc++.h>
#define N 200005
#define M 5000005
using namespace std;
int n,q,c[N],t[2*M];
string s[N][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	if(q*n<=2e8){
		while(q--){
			string t1,t2;
			int cnt=0;
			cin>>t1>>t2;
			for(int i=1;i<n;i++){
				int f=t1.find(s[i][0]);
				if(f>t1.size()) continue; 
				if(t1.substr(f,s[i][0].size())==t2.substr(f,s[i][1].size()))cnt++;
			}
			cout<<cnt<<'\n';
		}
	}
	else{
		for(int i=1;i<=n;i++){
			c[i]=s[i][0].find('b')-s[i][1].find('b');
			t[c[i]+M]++;
		}
		for(int i=1;i<=q;i++){
			string t1,t2;
			cin>>t1>>t2;
			int c=t1.find('b')-t2.find('b');
			printf("%d %d\n",c+M,t[c+M]);
		}
	}
	return 0;
} 
