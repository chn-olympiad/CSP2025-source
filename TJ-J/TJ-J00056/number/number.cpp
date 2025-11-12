#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	int ans=0;
	int a[100000];
	int p=0;
	cin>>s;
	for(int i=0;i<s.length();i++){		
		if(s[i]>='0' && s[i]<='9'){
			a[p]=s[i]-48;
			p++;			
		}
		
	}
	p-=1;
	sort(a,a+p+1);
	for(int i=p;i>=0;i--){
		ans=ans+a[i]*pow(10,i);
	}
	cout<<ans<<endl;
	return 0;
}


