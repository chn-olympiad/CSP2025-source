#include<bits/stdc++.h>
using namespace std;

string s;
int ans[1000005];
 
bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	int j=1;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0' && s[i]<='9'){
			ans[j]=s[i]-'0';
			j++;
		}
	}
	j--;
	sort(ans+1,ans+j+1,cmp);
	if(ans[1]!=0){
		for(int i=1;i<=j;i++){
			cout<<ans[i];
		}
	}else{
		cout<<0;
	}

	return 0;
}

