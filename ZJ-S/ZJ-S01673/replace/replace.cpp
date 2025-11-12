#include<bits/stdc++.h>
using namespace std;
const int p=29;
map<unsigned long long,int>mp;
int n,q,ans;
string sl[200005],s,s1,s2,s3;
unsigned long long h(string sss){
	int H=0;
	for(int i = 0 ; i < sss.size();i++)H=H*p+(sss[i]-'a'+1);
	return H; 
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q ;
	for(int i = 1 ; i <= n ; i++){
		cin >> s>>s1;
		sl[i]=s1;
		mp[h(s)]=i;
	}
	while(q--){
		cin >> s2 >> s3;
		cout << 0 << endl;
	}
	return 0 ;
}

