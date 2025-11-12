#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+50;
long long cnt;
char a[N];
string s,ans;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			cnt++;
			a[cnt]=s[i];
		}
	}
	sort(a+1,a+cnt+1);
	for(int i=cnt;i>0;i--){
		ans+=a[i];
	}
	cout<<ans;
	return 0;
}
