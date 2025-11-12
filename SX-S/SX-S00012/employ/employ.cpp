#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		if(s[i]==1){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}