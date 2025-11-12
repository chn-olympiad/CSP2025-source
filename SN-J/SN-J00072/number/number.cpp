#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000006],o=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int y=s.size();
	for(int z=0; z<y; z++){
		if(s[z]>='0'&&s[z]<='9'){
			a[o]=int(s[z]-'0');
			o++;
		}
	}
	sort(a,a+o);
	for(int z=o-1; z>=0; z--){
		cout<<a[z];
	}
	return 0;
} 
