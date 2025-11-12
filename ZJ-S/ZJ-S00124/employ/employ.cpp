#include<bits/stdc++.h>
using namespace std;
int n,m,a[505],d[505];
vector<int>b;string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m>>s;int ans=0;
	for(int i=1;i<=n;i++){
		cin>>d[i];
		b.push_back(i);
	}int x=count(d+1,d+n+1,0);
	do{int c=n-x;
		memcpy(a,d,sizeof d);
		for(int i=0;i<n;i++){
			if(s[i]=='0'){c--;
				for(int j=i+1;j<n;j++) c-=((--a[b[j]])<1);}
		}ans+=(c>=m);
	}while(next_permutation(b.begin(),b.end()));
	cout<<ans;
	return 0;
}
