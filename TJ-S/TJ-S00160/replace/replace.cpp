#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
char c[N][N],c2[N][N],a[N][N],a2[N][N];
int n,q,ans;
bool ch;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>c[i]>>c2[i];
	}
	for(int i=1;i<=q;i++){
		cin>>a[i]>>a2[i];
		if(strlen(a[i])!=strlen(a2[i])){
			cout<<"0"<<endl;
			continue;
		}
		ans=0;
		for(int k=1,o=0;k<=n;k++){
			o=0;
			for(int j=0;j<strlen(a[i])&&o<strlen(c[k]);){
				if(a[i][j]==c[k][o]){
					j++;
					o++;
					if(o>=strlen(c[k])){
						bool flag=true;
						for(int l=0;l<strlen(a[i]);){
							if(l<j-o||l>=j){
								if(a[i][l]!=a2[i][l]){
									flag=false;
								}
								l++;
							}else{
								for(int r=0;r<o;r++,l++){
									if(c2[k][r]!=a2[i][l]){
										flag=false;
									}
								}
							}
						}
						if(flag){
							ans++;
						}
					}
				}else{
					j++;
					o=0;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
