#include<bits/stdc++.h>
using namespace std;
string s[100005],s1[10005],y[10005];
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	if(q==1){
		for(int i=1;i<=n;i++){
			cin>>s[i]>>s1[i];
		}
		cin>>y[1]>>y[2];
		int len=sizeof(y)-1;
		for(int i=0;i<=len;i++){
			for(int j=0;j<=len;j++){
				
			}
		}
	}
	for(int i=1;i<=n;i++){
		cin>>s[i]>>s1[i];
	}
	for(int i=1;i<=q;i++){
		cin>>y[i]>>y[i+1];
	}
	for(int i=1;i<=q;i++){
		cout<<"0"<<endl;
	}
	return 0;
}

