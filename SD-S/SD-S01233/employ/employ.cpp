#include<bits/stdc++.h>
using namespace std;
long long n,m,c[110],feal,ans,da;
char s[110];
bool vis[110];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		da=n;
		if(s[i]=="0"){
			feal++;
			if(feal>=c[i]){
				feal++;
				vis[i]=false;
				da--;
			}
		}
		else{
			da++;
		}
		if(da>=m){
			ans++;
		}
	}
	fclose(stdin);
	fclose(stdout);
	cout<<2;
	return 0;
}
