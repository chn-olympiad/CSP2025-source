#include<bits/stdc++.h>
using namespace std;
long long a[10],cnt=-1,ans=0;
int main(){
	freopen("number.in",r,stdin);
	freopen("number.out",w,stdout);
	string s;
	cin>>s;
	long long l=s.length();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]]++;
			cnt++;	
		}
	}
	for(int i='9';i>='0';i--){
		if(a[i]!=0){
			for(int k=0;k<a[i];k++){
				ans+=(i-'0')*pow(10,cnt);
				cnt--;
			}
		}
	}
	cout<<ans;
	return 0;
}
