#include<iostream>
using namespace std;
const int N=510;
int s[N],c[N];
bool t1=1;//ÌØÊâA 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		char c;
		cin>>c;
		if (c=='0') s[i]=0;
		else s[i]=1;
		if (s[i]!=1) t1=0;
	}
	for (int i=1;i<=n;i++){
		cin>>c[i];
	}
	if (t1){
		int ans=1;
		for (int i=1;i<=n;i++){
			ans*=i;
		}
		cout<<ans;
	}
	return 0;
}
