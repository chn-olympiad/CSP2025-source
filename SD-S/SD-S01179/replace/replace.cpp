#include<bits/stdc++.h>
using namespace std;
long long n,q,ans=0;
vector<string> s1,s2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string x,y;
		cin>>x>>y;
		s1.push_back(x);
		s2.push_back(y);
	}
	while(q--){
		string x,y;
		cin>>x>>y;
		ans=0;
		for(int i=0;i<n;i++){
			string d;
			if(s1[i].length()>x.length()) continue;
			for(int j=0;j<=x.length()-s1[i].length();j++){
				d=x;
				int flag=1;
				for(int k=j;k<j+s1[i].length();k++){
					if(d[k]!=s1[i][k-j]){
						flag=0;
						break;
					}
					d[k]=s2[i][k-j];
				}
				if(flag==1&&d==y) ans++;
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
