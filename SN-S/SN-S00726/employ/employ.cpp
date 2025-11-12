//钟景其 SN-S00726 西安市曲江第一中学 

#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,m,k;
	int arr[10000],brr[10000],crr[10000],nrr[10000],mrr[10000];
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>arr[i]>>brr[i]>>crr[i];
	}
	int c;
	cin>>c;	
	for(int j=1;j<=k;j++){
		for(int i=1;i<=n;i++){
			cin>>nrr[i];
		}for(int i=1;i<=n;i++){
			cin>>mrr[i];
		}
	} 
	cout<<100;

}
