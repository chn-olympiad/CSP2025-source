#include<bits/stdc++.h>
using namespace std;
int a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>=97&&s[i]<=122)continue;
		a[int(s[i])-'0']++;
	}
	if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]==0)cout<<0<<endl;
	for(int i=9;i>=0;i--){
		while(a[i]!=0){cout<<i;a[i]--;}
	}
	return 0;
}
