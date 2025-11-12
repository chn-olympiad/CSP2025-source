#include<bits/stdc++.h>
using namespace std;
string s;
const int N=1e6+10;
int a[N],cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);	
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(isdigit(s[i])){
			a[++cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+cnt+1);
	reverse(a+1,a+cnt+1);
	if(a[1]==0){
		int pt=0;
		while(a[pt]==0 and pt<=cnt){
			pt++;
		}
		swap(a[pt],a[1]);
	}
	for(int i=1;i<=cnt;i++){
		cout<<a[i];
	}
	return 0;
}
