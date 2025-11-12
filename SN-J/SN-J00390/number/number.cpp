#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a[1000005],id=0,sum=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(49<=int(s[i])&&int(s[i])<=57){
			a[id]=int(s[i]-48);
			id++;
		}
	}
	sort(a,a+id);
	for(int i=0;i<id;i++){
		int c=1;
		sum+=a[i]*c;
		c=c*10;
	}
	cout<<sum;
	return 0;
}
