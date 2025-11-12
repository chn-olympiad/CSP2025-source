#include<bits/stdc++.h>
using namespace std;
string s;
int n,cnt=1,ans,a[10005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[cnt]=s[i]-'0';
			
			cout<<a[cnt]<<" "<<s[i]<<endl;
			cnt++;
		}
	}
	sort(a+1,a+cnt-1+1);
	for(int i=cnt-1;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
