#include<bits/stdc++.h>
using namespace std;
int n,q;
string a[210000],b[210000];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	/*if(q==1){
		string c,d;
		cin>>c>>d;
		if(c.length()!=d.length())cout<<0;
		else{
			int I,J;
			for(int i=0;i<c.length();i++){
				if(c[i]!=d[i]){
					I=i;
					break;
				}
			}
			for(int i=c.lentgh()-1;i>=0;i--){
				if(c[i]!=d[i]){
					J=i;
					break;
				}
			}
			int k=J-I+1;
			for(int i=1;i<=n;i++){
				if(a[i].length()<k) continue;
				for(int j=1;)
			}
		}
		
		for(int i=1;i<=n;i++){
			
		}
	}*/
	if(n<=1000 && q<=1000){
		for(int shy=1;shy<=q;shy++){
			string c,d;
			cin>>c>>d;
			int I,J;
			for(int i=0;i<c.length();i++){
				if(c[i]!=d[i]){
					I=i;
					break;
				}
			}
			for(int i=c.length()-1;i>=0;i--){
				if(c[i]!=d[i]){
					J=i;
					break;
				}
			}
			int k=J-I+1;
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=0;j<=c.length();j++){
					if(c[j]==a[i][0] && k<=a[i].length()){
						int ok=0;
						for(int k=0;k<a[i].length();k++){
							if(a[i][k]!=c[j+k]){
								ok=1;
								break;
							}
						}
						if(!ok){
							for(int k=0;k<b[i].length();k++){
								if(b[i][k]!=d[j+k]){
									ok=1;
									break;
								}
							}
							if(!ok) ans++;
						}
					}
				}
			}		
			cout<<ans<<"\n";
		}
	}
	return 0;
}