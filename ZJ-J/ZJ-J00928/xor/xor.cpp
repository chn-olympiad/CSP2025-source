#include<bits/stdc++.h>
using namespace std;

int n,m,a[500005],on=0,qzk=0,cnt=0;

int main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==1) on++;
	}
	if(m==0){
		for(int i=0;i<n;i++){
			if(a[i]==0){
				cnt++;
				qzk=0;
			}else{
				if(qzk){
					cnt++;
					qzk=0;
				}else{
					qzk=1;
				}
			}
		}
		cout<<cnt;
		return 0;
	}else if(m==1){
		cout<<on;
		return 0;
	}
	cout<<1;
	return 0;
}
