#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,ans=0;
pair <int,int> a[N];
pair <int,int> b[N];
string s,t; 
//bool check(pair <int,int> )
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s>>t;
		int len=s.size();
		for(int i=0;i<len;i++){
			if(s[i]=='b'){
				a[N]={i,len-i-1};
			}
		}
		for(int i=0;i<len;i++){
			if(t[i]=='b'){
				b[N]={i,len-i-1};
			}
		}
	}
	while(m--){
		cin>>s>>t;
		pair <int,int> x;
		pair <int,int> y;
		int len=s.size();
		for(int i=0;i<len;i++){
			if(s[i]=='b'){
				x={i,len-i-1};
			}
		}
		for(int i=0;i<len;i++){
			if(t[i]=='b'){
				y={i,len-i-1};
			}
		}
//		for(int i=1;i<=n;i++) if(check(a[i],b[i],x,y)) ans++;
		cout<<ans;
	}
	return 0;
}

