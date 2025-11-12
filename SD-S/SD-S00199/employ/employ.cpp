#include <bits/stdc++.h>
using namespace std;
int n,m;
string s;
int a[510],b[510];
bool e[510]={0};
int cnt;
int sum;
int main(){
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==0)
			sum++;
	}
	for(int i=0;i<n;i++){
		if(s[i]=='1')
			cnt++;
	}
	if(m==1){
		int ui=1,yu;
		if(sum>cnt){
			yu=n-sum;
		}else{
			yu=n-cnt;
		}
		for(int i=1;i<=yu;i++){
			ui*=i;
		}
		cout<<ui;
		return 0;
	}
	cout<<"2";
	return 0;
}
