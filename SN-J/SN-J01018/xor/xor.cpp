//SN-J01018  赵晗羽  西安辅轮中学 
#include<bits/stdc++.h>
using namespace std;
int n,k,a[200005],b,bj[200005],bj1[200005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0)b=1;
	}
	if(b){
		if(k==0){
			int s=0;
			for(int i=2;i<=n;i++){
				if(a[i]==a[i-1]&&bj1[i-1]==0){
					s++;
					bj1[i]=1;
				}else{
					a[i]=a[i]^a[i-1];
				}
			}
			cout<<s;
		}else{
			int s=0;
			for(int i=2;i<=n;i++){
				if((a[i]==1&&a[i-1]==0&&bj[i-1]==0)||(a[i]==0&&a[i-1]==1&&bj[i-1]==0)){
					s++;
					bj[i]=1;
				}
			}
			cout<<s;
		}
	}else{
		cout<<n/2;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
