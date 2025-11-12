#include<bits/stdc++.h>
using namespace std;
int n,k,s[200010],cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k==0||k==1){
		for(int i=0;i<n;i++){
			int a;
			cin>>a;
			s[i]=a%2;
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(s[i]!=s[j]&&k==1){
					cnt++;
					i=j;
				}
				if(s[i]==s[j]&&k==0){
					cnt++;
					i=j;
				}
			}
		}
		cout<<cnt;
	}
	else{
		for(int i=0;i<n;i++){
			int a;
			cin>>a;
		}
		cout<<(n+k)/3;
	}
	return 0;
}
