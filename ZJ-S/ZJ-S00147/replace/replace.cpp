#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
char s[2][N],t[2][N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[1]>>s[2];
	}
	for(int i=1;i<=q;i++){
		int sum=0;
		cin>>t[1]>>t[2];
		int lent=strlen(t[1]);
		for(int j=1;j<=n;j++){
			int lens=strlen(s[1]);
			for(int k=0;k<lent-lens+1;k++){
				int flag=1;
				for(int k1=k;k1<k+lens;k1++){
					if(t[1][k]!=s[1][k]){
						flag=0;
						break;
					}
				}
				if(flag==1){
					for(int k1=k;k1<k+lens;k1++){
						if(t[2][k]==s[2][k]){
							sum++;
						}
					}
				}
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}
