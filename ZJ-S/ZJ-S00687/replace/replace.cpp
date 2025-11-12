#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string a[N],b[N],c,d;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(long long i=1;i<=n;i++)
		cin>>a[i]>>b[i];
		if(q==1){
		cin>>c>>d;
			for(long long i=1;i<=n;i++)
			{
				if(c==a[i]&&d==b[i]){
				cout<<2<<endl;
				break;
			}else if(c==a[i]||d==b[i]){
				cout<<1<<endl;
				break;
			}
			else{
				cout<<0<<endl;
				break;
			}
			}
		}else{
		for(long long i=1;i<=q;i++)
		cout<<0<<endl;
	}
	return 0;
}