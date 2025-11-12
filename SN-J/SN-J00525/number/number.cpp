#include<bits/stdc++.h>
using namespace std;
#define ll long long
string a;
int as[20]={};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>a;
	int lena=a.size();
	for(int i=0;i<lena;i++){
		if(a[i]>='0'&&a[i]<='9'){
			as[a[i]-48]++;
			//cout << a[i]-48;
		}
	}
	int cnt=0;
	for(int i =9;i>=0;i--){
		while(as[i]){
			if(i!=0)cnt++;
			if(i!=0||cnt!=0)cout << i;
			//cout <<" "<<as[i];
			as[i]--;
		}
	}
	if(!cnt)cout <<0;
	return 0;
}
//as43dfdfg43fd219
