#include<bits/stdc++.h>
using namespace std;
string s;
int t,n,i,a[1000006];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	t=1;i=0;n=s.size();
	while(1){
		if(i==n){
			break;
		}
		if(s[i]>='0'&&s[i]<='9'){
			a[t]=s[i]-48;
			t++;
		}
		i++;
	}
	t--;
	sort(a+1,a+1+t);
	for(i=t;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
