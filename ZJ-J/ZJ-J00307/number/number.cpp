#include <bits/stdc++.h>
#define int long long
using namespace std;
string str;
int k,num[1000005];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	int	n=str.size();
	str=' '+str;
	k=0;
	for(int i=1;i<=n;i++){
		if('0'<=str[i] && str[i]<='9'){
			k++;
			num[k]=str[i]-'0';
		}
	}
	sort(num+1,num+k+1,cmp);
	if(num[1]==0){
		cout<<0;
		return 0;
	}
	else{
		for(int i=1;i<=k;i++)
			cout<<num[i];
	}
	return 0;
}