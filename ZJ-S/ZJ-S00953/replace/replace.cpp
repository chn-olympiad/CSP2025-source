#include<bits/stdc++.h>
using namespace std;
int n,q;
string compere1[200005],compere2[200005];
int f(){
	string a,b;
	int ans=0;
	cin>>a>>b;
	if(a.size()!=b.size()){
		return 0;
	}
	int len=a.size();
	for(int i=1;i<=n;i++){
		for(int j=0;j<len;j++){
			string tmp=a;
			int flag=1;
			for(int p=j;p<j+compere1[i].size();p++){
				if(a[j]!=compere1[i][p-j]){
					//cout<<compere1[i][p-j];
					flag=0;
					break;
				}
				else{
					tmp[j]=compere2[i][p-j];
				}
			}
			//cout<<endl;
			if(tmp==b&&flag==1){
				ans++;
			}
		}
	}
	return ans;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>compere1[i]>>compere2[i];
	}
	while(q--){
		cout<<f()<<endl;
	}
	return 0;
}

