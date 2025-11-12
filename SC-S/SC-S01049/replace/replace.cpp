#include<bits/stdc++.h>
using namespace std;
long long n,q,cnt=0,ls=0,la[10017];
string a[10017],b[10017];
string s,t,zt;
bool flag=true;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		la[i]=a[i].length();
	}
	for(int i=1;i<=q;i++){
		cnt=0;
		cin>>s;
		cin>>t;
		ls=s.length();
		for(int j=1;j<=n;j++){
			for(int k=0;k<=ls-la[j];k++){
				flag=true;
				zt=s;
				for(int w=0;w<la[j];w++){
					zt[k+w]=b[j][w];
					if(s[k+w]!=a[j][w]){
						flag=false;
						break;
					}
				}
				if(flag){
					if(zt==t) cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}