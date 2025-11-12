#include<bits/stdc++.h>
using namespace std;
string s; 
int m[100005],siz;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<'a'){		
			m[siz]=s[i]-'0';
			siz++;
		}
	}
	sort(m,m+siz+1);
	for(int i=siz;i>0;i--){
		cout<<m[i];
	}
}

