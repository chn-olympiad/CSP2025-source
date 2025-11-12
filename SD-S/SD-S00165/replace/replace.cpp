#include<bits/stdc++.h>
using namespace std;
struct asd{
	string a,b;
};
asd a[50010],b[50010];
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].b;
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		cin>>b[i].a>>b[i].b;
		int c=b[i].a.length();
		for(int l=0;l<c;l++){
			for(int r=l;r<c;r++){
				string x,y,z;
				for(int j=0;j<l-1;j++){
					x+=b[i].a[j];
				}
				for(int j=l-1;j<r;j++){
					y+=b[i].a[j];
				}
				for(int j=r;j<c;j++){
					z+=b[i].a[j];
				}
				for(int j=1;j<=n;j++){
					if(a[j].a==y){
						y=a[j].b;
						if(x+y+z==b[i].b){
//							cout<<"x:"<<x<<"\n"<<"y:"<<y<<"\n"<<"z:"<<z<<"\n";
							ans++;
						}
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
}

