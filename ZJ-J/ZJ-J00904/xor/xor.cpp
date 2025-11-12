#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10;
int n,k;
int a[N];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int pt=1,sum;
	int xorTmp,DTmp;
	bool flag=0,flag2=1;
	while(pt<=n){
		xorTmp=0;
		flag2=1;
		for(int i=pt;i<=n;i++){
			DTmp=0;
			for(int j=i;j>pt;j--){
				DTmp=DTmp^a[j];
				if(DTmp==k){
					pt=i+1;
					sum++;
					flag=1;
					flag2=0;
					break;
				}
			}
			if(flag){
				flag=0;
				break;
			}
			xorTmp=xorTmp^a[i];
			if(xorTmp==k){
				pt=i+1;
				sum++;
				flag2=0;
				break;
			}
		}
		if(flag2){
			break;
		}
	}
	cout<<sum;
	
	cout<<endl;
	

	return 0;
}

