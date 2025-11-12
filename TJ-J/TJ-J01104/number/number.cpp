#include<bits/stdc++.h>
using namespace std;
string ans="";
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int ls=s.size();
	int p=0;
	int q[ls+3]={0};
	for(int i=0;i<ls;i++){
		if(s[i]>='0'&&s[i]<='9'){
			q[p]=s[i]-'0';p++;
		}
	}
	sort(q,q+p);
	for(int i=p-1;i>=0;i--){
		if(ans=="0")continue;
		ans+=q[i]+'0';
	}
	cout<<ans<<endl;
	return 0;
}
