#include<bits/stdc++.h>
using namespace std;
//我也想吃巧克力(好香啊QAQ) 
int n,m,k;
int a1[1000005];
int a2[1000005];
int a3[1000005];
int l[13][1000005];
long long rp;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>a1[i]>>a2[i]>>a3[i];
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			cin>>l[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		rp+=a3[i];//QAQ能不能让我过一个点 
	}
	cout<<rp; 
	return 0;
}
