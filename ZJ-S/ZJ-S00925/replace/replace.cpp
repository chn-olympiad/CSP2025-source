#include<bits/stdc++.h>
using namespace std;
int n,q;
map<string,string> mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		string a,b;
		cin>>a>>b;
		mp[a]=b;
	}
	for(int i=1;i<=q;i++){
		string a,b;
		cin>>a>>b;
		long long cnt=0;
		for(int l=0;l<a.size();l++)
			for(int r=a.size()-1;r>=l;r--){
				string now=a.substr(l,r-l+1);
				if(mp.count(now)){
//					cout<<l<<" ";
					string nowx=a.substr(0,l);
//					cout<<nowx<<" ";
					nowx+=mp[now];
//					cout<<nowx<<" ";
					nowx+=a.substr(r+1,n-r);
//					cout<<nowx<<"\n";
					if(nowx==b)		cnt++;
				}
			}
		printf("%lld\n",cnt);
	}
	return 0;
}
