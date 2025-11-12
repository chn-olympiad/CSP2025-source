#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
string a[N],b[N],c[N],d[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,sum=0;
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=q;i++){
		cin>>c[i]>>d[i];
		for(int j=1;j<=n;j++){
			if(c[i]==a[j] and d[i]==b[j]){
				sum+=2;	
			}
		}
		cout<<sum<<endl;
		sum=0;
	}
	return 0;
}
