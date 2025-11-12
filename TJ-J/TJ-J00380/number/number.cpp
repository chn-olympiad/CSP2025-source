#include<iostream>
using namespace std;
int a[11]={0};
int l;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]<='9'&&s[i]>='0') a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++) cout<<i;
	}
	return 0;
}
//CSP-J Journal
//8:45 Number Complete.
//     Maybe I'll Test The Big Files Later.
//     RP++.Luogu Bless Me!Kkksc03 Bless Me!Yifusuyi Bless Me!
//     I Love ccf!
//10:33 Test Completed.
