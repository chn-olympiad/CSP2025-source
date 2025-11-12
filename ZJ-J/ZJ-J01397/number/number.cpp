#include<bits/stdc++.h>
using namespace std;
int ans[1000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int k=0;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			ans[k]=(a[i]-'0');
			k++;
		}
	}
	sort(ans,ans+k);
	if(ans[k-1]==0) cout<<0;
	else{
		for(int i=k-1;i>=0;i--){
			cout<<ans[i];
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
