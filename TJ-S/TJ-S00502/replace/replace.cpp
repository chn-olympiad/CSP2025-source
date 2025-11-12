#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int n,q,cnt=0;
string m,a;
char same[200005],diff[200005];
struct word{
	string x;
	string y;
}s[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i].x>>s[i].y;
	}
	while(q>0){
		cin>>m>>a;
		if(m.size()!=a.size()){
			cout<<0;
			continue;
		}
		for(int i=1;i<=n;i++){
			if(s[i].x==m && s[i].y==a) cnt++;
		}
		q--;
		cout<<cnt;
		cnt=0;
	}
	return 0;
}
