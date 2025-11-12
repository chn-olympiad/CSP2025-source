#include<bits/stdc++.h>
using namespace std;
int n,m,l[200010],r[200010],y[200010],w[200010];
string a[200010],b[200010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		w[i]=a[i].length();
		if(a[i]==b[i]){
			i--;
			n--;
		}
		else{
			int t=a[i].length();
			a[i]=' '+a[i];
			b[i]=' '+b[i];
			int flag1=0,flag2=0;
			for(int j=1;j<=t;j++){
				if(a[i][j]=='b'){
					l[i]=j-1;
					flag1=1;
				}
				else if(b[i][j]=='b'){
					r[i]=j-1;
					flag2=1;
				}
				if(flag1==1&&flag2==1){
					break;
				}
			}
			y[i]=l[i]-r[i];
		}
	}
	for(int i=1;i<=m;i++){
		cin>>a[i]>>b[i];
		int t=a[i].length();
		a[i]=' '+a[i];
		b[i]=' '+b[i];
		int flag1=0,flag2=0,x,z,e,ans=0;
		for(int j=1;j<=t;j++){
			if(a[i][j]=='b'){
				x=j-1;
				flag1=1;
			}
			else if(b[i][j]=='b'){
				z=j-1;
				flag2=1;
			}
			if(flag1==1&&flag2==1){
				break;
			}
		}
		e=x-z;
		for(int j=1;j<=n;j++){
			if(x>=l[i]&&t-z-1>=w[i]-l[i]-1&&y[i]==e){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}