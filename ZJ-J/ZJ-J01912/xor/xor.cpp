#include<bits/stdc++.h>
using namespace std;
int n,k,res,l=1;
long long a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(l<=n){
		int ans=0;
		bool b=0;
		for(int i=l;i<=n;i++){
			int x=ans^a[i];
			ans=x;
			if(ans==k){
				res++;
				l=i+1;
				b=1;
				break;
			}
		}if(b==0)l++;
	}
	cout<<res;
	fclose(stdin);
	fclose(stdout);
	return 0;
}