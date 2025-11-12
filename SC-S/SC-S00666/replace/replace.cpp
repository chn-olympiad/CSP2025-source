#include<bits/stdc++.h>
using namespace std;
long long int n,q,a[200005],b[200005][3],x,ans;
string qwe,asd;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>qwe>>asd;
		for(int j=0;j<qwe.size();j++){
			if(qwe[j]=='b'){
				x=j;
				b[i][1]=j;
				b[i][2]=qwe.size()-j;
				break;
			}
		}
		for(int j=0;j<asd.size();j++){
			if(asd[j]=='b'){
				a[i]=x-j;
				break;
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>qwe>>asd;
		for(int j=0;j<qwe.size();j++){
			if(qwe[j]=='b'){
				x=j;
				break;
			}
		}
		for(int j=0;j<asd.size();j++){
			if(asd[j]=='b'){
				for(int k=1;k<=n;k++){
					if((x-j)==a[k]&&x>=b[k][1]&&qwe.size()-x>=b[k][2]){
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
} 