#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010];
int maxx;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9' && s[i]>='0'){
			maxx=max(maxx,int(s[i]));
			a[int(s[i])-'0']++;
		} 
	}
	for(int i=maxx;i>=0;i--){
		if(a[i]) {
			for(int j=1;j<=a[i];j++)cout<<i;
		}
	}
	return 0;
} 
