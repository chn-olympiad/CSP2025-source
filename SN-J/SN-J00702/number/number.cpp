#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
ll num[1000000+5],cnt=1;
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			num[cnt]=s[i]-'0';
			cnt++;
		}
	}
	sort(num+1,num+cnt,cmp);
	//for(int i=1;i<=cnt-1;i++){
	//	cout<<num[i]<<" ";
	//}
	if(num[1]==0){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=cnt-1;i++){
		cout<<num[i];
	}
	return 0;
}
/*
          CCF	
          
    \      |      /
     \     |     /      
      \    |    /  
       \   |   /
        \  |  /
        -------
       /       \
       \       /
        -------
*/

