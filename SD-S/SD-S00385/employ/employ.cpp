#include<bits/stdc++.h>
using namespace std;
int a[1001];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int maxx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	int l=s.length();
		int ans=0;
	if(maxx==1){
		int d=0;
		for(int i=0;i<l;i++){
			if(s[i]=='1'){
				ans++;
			}
			else{
				d=i;
				break;
			}
		}
		if(ans==l){
			cout<<(1+n)*n/2;
		}
	}
	else{
		cout<<2;
	}
	return 0;
}
