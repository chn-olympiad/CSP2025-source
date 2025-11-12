#include <iostream>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
struct node{
	string a,b;
}s[100005],t[100005];
map <string,string> mp;
set <string> st;
long long cnt;
bool cmp(node a,node b){
	return a.a<b.a;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].b;
		mp[s[i].a]=s[i].b;
		st.insert(s[i].a);
	}
	for(int i=1;i<=q;i++){
		cin>>t[i].a>>t[i].b;
		int len=t[i].a.size();
		cnt=0;
		for(int j=0;j<len;j++){
			for(int k=j;k<len;k++){
				string x=t[i].a.substr(0,j);
				string y=t[i].a.substr(j,(k-j+1));
				string z=t[i].a.substr(k+1,len-k);
				string s2="";
				if(st.find(y)!=st.end()){
					y=mp[*st.find(y)];
					s2=x+y+z;
				}
				if(s2==t[i].b){
					cnt++;
				}
			}
		}
		printf("%lld\n",cnt);
	}
}
