#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string a[n][2],b[q][2];
	for(int i=0;i<n;i++){
		cin>>a[i][0]>>a[i][1];
	}
	for(int i=0;i<q;i++){int ans=0;
		cin>>b[i][0]>>b[i][1];
		for(int j=0;j<n;j++){
			string x=b[i][0];
			if(b[i][0].find(a[j][0])>=0){
				for(int k=b[i][0].find(a[j][0]);k<a[j][0].size();k++){
					x[k]=a[j][1][k];
				}
				if(x.compare(b[i][1])==0){
					ans++;
				}
			}
			else if(b[i][1].compare(a[j][1])==0 && b[i][0].compare(a[j][0])==0){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
