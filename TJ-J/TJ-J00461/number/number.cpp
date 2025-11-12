#include<bits/stdc++.h>
using namespace std;
string n;
int ans[8000010];
int tmp;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(int i=0;i<n.size();i++){
		if(n[i]>='0' && n[i]<='9'){
			ans[tmp]=n[i]-'0';
			tmp++;
		}
		else continue;
	}
	sort(ans,ans+tmp);
	for(int i=tmp-1;i>=0;i--){
		cout<<ans[i];
	}
	return 0;
} 
