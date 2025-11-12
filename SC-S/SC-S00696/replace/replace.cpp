#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
string a[N],b[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int M=1;M<=m;M++){
		int ans=0;
		string t1,t2,T;
		cin>>t1>>t2;
		for(int i=1;i<=(int)t1.size();i++){
			T=t1;
			for(int j=1;j<=n;j++){
				bool qwe=1;
				for(int k=1;k<=(int)a[j].size();k++){
					if(t1[i+k-2]!=a[j][k-1]||b[j][k-1]!=t2[i+k-2]){
						qwe=0;
						break;
					}else{
						T[i+k-2]=b[j][k-1];
					}
				}
				if(qwe&&T==t2){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}