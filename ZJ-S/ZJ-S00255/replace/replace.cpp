#include<bits/stdc++.h>
using namespace std;
#define N 10004
#define fi first
#define se second
#define ll long long
#define inf 0x3f3f3f3f
#define pii pair<int,int>
int n,q;
map<string,string> mp;
string x,y;
string s,d;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		mp[x]=y;
	}
	while(q--){
		int sum=0;
		cin>>s>>d;
		int len=min(d.size(),s.size());
		for(int i=0;i<len;i++){
			for(int j=1;j<=len-i;j++){
				string tmp=s.substr(i,j);
				string tmpd=d.substr(i,j);
				string ttmp=s.substr(i+j,n-j+1);
				string ttmpd=d.substr(i+j,n-j+1);
				string tm=s.substr(0,i);
				string ttm=d.substr(0,i);
				if(mp[tmp]==tmpd&&ttmp==ttmpd&&tm==ttm){
					sum++;
				}
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}