#include<bits/stdc++.h>
using namespace std;char s;int a[1000002],cnt=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>s){
		if(s>='0'&&s<'9'){
			a[(int)(s-'0')]+=1;;
		}
		if(s=='9'){
			cout<<9;
		}
	}
	for(int i=8;i>=0;i--){
		for(int j=0;j<a[i];j++){
			cout<<i;
		}
	}
	return 0;
}