#include <bits/stdc++.h>
using namespace std;
int main(){
	freeopen("club.in","r",stdin);
	freeopen("club.out","w",stdout);
	int t=0;
	int a1[100005],a2[100005],a3[100005],n;
	int maxn[6]={};
	cin>>t; 
	for(int h=0;h<t;h++){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
		}if(n==2){
			maxn[h]=max(a1[0]+a2[1],max(a1[0]+a3[1],max(a2[0]+a1[1],max(a2[0]+a3[1],max(a3[0]+a1[1],a3[0]+a2[1])))));
		}
	}for(int h=0;h<t;h++){
		cout<<maxn[h]<<endl;
	}
	return 0;
}