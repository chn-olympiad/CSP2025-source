#iclude<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	unsigned long long lin;
	cin>>n;
	vector<unsigned long long>sum(n);
	unsigned long long s=0;
	for (int i=0;i<n;i++){
		cin>>lin;
		s+=lin;
		sum[i]=s;
	}
	long long ant=0;
	for (int i=0;i<n-1;i++){
		for (int j=i+2;j<n;j++){
			if (sum[j]-sum[i]>2*(*max_element(sum+i,sum+j+1)){
				ant+=ant%998244353;
				ant%=998244353;
			}
		}
	}
	cout<<ant;
	return 0;
}
