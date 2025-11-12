#include<bits/stdc++.h>
using namespace std;
string a;
int  num;
int ans[100001];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int n=a.size();
	for(int i=0;i<n;i++){
		if(a[i]>='0' and a[i]<='9'){
			ans[num++]=a[i]-'0';
		}
	}
	sort(ans,ans+num,cmp);
	for(int i=0;i<num;i++){
		cout<<ans[i];
	}
	
	
	return 0;
}
