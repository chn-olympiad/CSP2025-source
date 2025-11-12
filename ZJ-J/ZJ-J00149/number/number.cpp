#include<bits/stdc++.h>
using namespace std;
string s;
int v[1000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
//    freopen("ans.out","w",stdout);
	cin>>s;
	int len=s.size(),k=0;
	for(int i=0;i<len;i++){
		if(s[i]-'0'>=0&&s[i]-'0'<=9){
			k++;
			v[k]=s[i]-'0';
		}
	}
	sort(v+1,v+1+k);
	for(int i=k;i>=1;i--){
		cout<<v[i];
	}
	return 0;
}