# include<bits/stdc++.h>
using namespace std;
string s;
int a[100010]={0};
long long cnt=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	for(int i=0;i<s.size();i++){
		if(s[i]>47&&s[i]<58){
			a[i]=s[i]-'0';
		}else{
			cnt++;
		}
	}
	sort(a,a+s.size());
	for(int i=s.size()-1;i>=cnt;i--){
		cout<<a[i];
	}
	return 0;
}
