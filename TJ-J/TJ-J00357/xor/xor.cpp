#include<iostream>
#include<vector>
using namespace std;
int a[500005],f[500005],b[1100000];
vector<int> c;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,x=-1;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(x==-1){
			x=a[i];
		}else{
			x=x^a[i];
		}
		if(x==k || b[(k^x)]==1){
			f[i]=f[i-1]+1;
			x=-1;
			for(int i=0;i<c.size();i++){
				b[c[i]]=0;
			}
			c.clear();
		}else{
			f[i]=f[i-1];
			b[x]=1;
			c.push_back(x);
		}
	}
	cout<<f[n];
	return 0;
}
