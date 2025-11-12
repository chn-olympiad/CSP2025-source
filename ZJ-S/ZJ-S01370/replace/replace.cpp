#include<bits/stdc++.h>
using namespace std;
long long n,m,t,sum;
string a[300000],b[300000],p,x,y;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	for(int i=1;i<=m;i++){
		sum=0;
		cin>>x>>y;
		for(int j=1;j<=n;j++){
			t=x.find(a[j]);
			if(t>=0){
				p=x,p.erase(t,a[j].size()),p.insert(t,b[j]);
				if(p==y) sum++;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}