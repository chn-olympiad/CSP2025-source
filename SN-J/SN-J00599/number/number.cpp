#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N]; 
string s;
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int ans=1; 
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			a[ans]=0;
			ans++;
		}if(s[i]=='1'){
			a[ans]=1;
			ans++;
		}
		if(s[i]=='2'){
			a[ans]=2;
			ans++;
		}
		if(s[i]=='3'){
			a[ans]=3;
			ans++;
		}
		if(s[i]=='4'){
			a[ans]=4;
			ans++;
		}
		if(s[i]=='5'){
			a[ans]=5;
			ans++;
		}
		if(s[i]=='6'){
			a[ans]=6;
			ans++;
		}
		if(s[i]=='7'){
			a[ans]=7;
			ans++;
		}
		if(s[i]=='8'){
			a[ans]=8;
			ans++;
		}
		if(s[i]=='9'){
			a[ans]=9;
			ans++;
		}
	}
	sort(a+1,a+ans);
	for(int i=ans-1;i>0;i--){
		cout<<a[i];
	}
	return 0;
}
