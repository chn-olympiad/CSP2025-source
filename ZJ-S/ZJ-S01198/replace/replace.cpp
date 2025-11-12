#include<bits/stdc++.h>
using namespace std;
string s[200005][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		int ans=0;
		int lt=t1.size();
		for(int i=0;i<lt;i++){
			for(int j=i;j<lt;j++){
				string u1=t1.substr(i,j-i+1);
				for(int k=1;k<=n;k++){
					if(u1==s[k][0])u1=s[k][1];
				}
				if(t1.substr(0,i)+u1+t1.substr(j+1,lt-j)==t2)ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
