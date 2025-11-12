#include<iostream>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long a[1000],k;
	int iy[10000],ky[10000],js=0;
	int n;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	long long q;
	for(int i=0;i<n;i++){
		q=i;
		if(q==k){
			iy[js]=i;
			ky[js]=i;
			js++;
		}
		for(int k=i+1;k<n;k++){
			q=q^a[k];
			if(q==k){
				iy[js]=i;
				ky[js]=k;
				js++;
			}
		}
	}
	cout<<js<<endl;
	//for(int i=0;i<js;i++){
		//for(int k=0;k<js;k++){
		//	break;
		//}
	//}
	return 0;
}

