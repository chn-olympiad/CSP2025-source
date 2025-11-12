#include<bits/stdc++.h>
using namespace std;
string s;
long long a[100005];
long long j;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0;i<s.size();i++){
		if(int(s[i])>47&&int(s[i])<58){
			a[j]=int(s[i])-48;
			j++;
		}
	}
	sort(a,a+j+1);
	for(long long i=j;i>0;i--){
		cout<<a[i];
	}
	return 0;
}
