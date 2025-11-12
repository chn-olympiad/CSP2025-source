#include<iostream>
using namespace std;
string aa[200005][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n;
	cin>>n;
	int q;
	cin>>q;
	for(int i=1;i<=n;i++){
		cin>>aa[i][1]>>aa[i][2];
	}
	for(int i=1;i<=q;i++){
		string a,b;
		cin>>a>>b;
		int ans=0;
		for(int i=0;i<a.length();i++){
			for(int l=1;l<=a.length()-i;l++){
				string nowa=a.substr(i,l);
				for(int k=1;k<=n;k++){
					if(aa[k][1]==nowa){
						cout<<nowa<<endl;
						bool cg=false;
						for(int j=0;j<b.length();j++){
							for(int lb=1;lb<=b.length()-j;lb++){
								if(b.substr(j,lb)==aa[k][2]&&!cg){
									cg=true;
									ans++;
									break;
								}
								if(cg) break;
							}
							if(cg) break;
						}
						//ans++;
						break;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
