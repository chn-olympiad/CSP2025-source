#include <bits/stdc++.h>
#define ll long long
using namespace std;
string num1[10001],num2[10001];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>num1[i]>>num2[i];
	}
	while(q--){
		string a,b;
		int ans=0;
		int first=0,last=0,f=0;
		cin>>a>>b;
		for(int i=0;i<a.size();i++){
			if(a[i]!=b[i]&&!f){
				first=i;
				f=1;
				last=i;
			}
			else if(a[i]!=b[i]){
				last=i;
			}
		}
		for(int i=0;i<=first;i++){
			for(int j=last;j<a.size();j++){
				string qp="",man="";
				for(int k=i;k<=j;k++){
					qp+=a[k];
					man+=b[k];
				}
				for(int k=1;k<=n;k++){
					if(num1[k]==qp&&num2[k]==man){
						ans++;
					}
				}
			}
		}
		cout<<ans;
	}
	return 0;
}

