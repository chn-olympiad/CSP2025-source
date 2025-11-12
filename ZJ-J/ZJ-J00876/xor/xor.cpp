#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,MAX=(1<<20)+10;
int n,k,lst=-1;
int a[N],p[MAX];
int sum,ans,s;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	for(int i=1;i<=(1<<20);i++)p[i]=-1;
	cin>>n>>k;
	p[0]=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum^=a[i];
		if(a[i]==1)s++;
		int x=sum^k;
		if(p[x]>lst){
			lst=i;
			ans++;
		}
		p[sum]=i+1;
	}cout<<ans;
	return 0;
}
