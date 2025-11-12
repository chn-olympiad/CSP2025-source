#include<bits/stdc++.h>
using namespace std;
long long n,k,a[10010],cnt1=0,cnt2=0,tmp1,l=1,r=1,tmp2[10010],b[10010];//,tmp3;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			cnt1++;
			tmp2[i]/*=tmp3*/=i;
		}
	}
	for(l=1;l<n;l++){
		for(r=l+1;r<=n;r++){
			tmp1=l;
			bool f=true;
			for(int i=l+1;i<=r;i++){
				for(int j=1;j<=n;j++){
					if(tmp2[j]==i){
						f=false; 
					//	cout<<"1"<<endl;
					}
				}
				//tmp3=i^tmp1;
				tmp1^=a[i];
				//cout<<tmp1<<' ';
			}
			if(tmp1==k/*(||tmp3==k)*/&&f==true){
				cnt1++;
				//cout<<tmp1;	
			}
		}
	}
	cout<<cnt1;
	return 0;
}
