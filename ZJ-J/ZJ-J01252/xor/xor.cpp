#include<bits/stdc++.h>
using namespace std;
int n,k,AC,a[5000005],b[5000005],tail;
bool flag=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		flag=0;
		if(a[i]==k){
			tail=0;
			AC++;
			continue;
		}
		for(int j=1;j<=tail;j++){
			b[j]^=a[i];
			if(b[j]==k){
				tail=0;
				AC++;
				flag=1;
				break;
			}
		}
		if(!flag) b[++tail]=a[i];
	}
	cout<<AC;
	return 0;
}
