#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,k,a[N],x[N],ans=0,tot=0;
bool b[N];
void search(int i){
	bool f=false;
	for(int j=i;j<=n;j++){
		if((x[i-1]^x[j])==k){
			f=true;
			b[i]=true;
			tot++;
			search(j+1);
			tot--;
		}
	}
	if(f==false)ans=max(ans,tot);
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	x[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		x[i]=x[i-1]^a[i];
	}
	for(int i=1;i<=n-1;i++){
		if(b[i]==true)continue;
		else{
			memset(b,false,sizeof(b));
			search(i);
		}
	}
	cout<<ans;