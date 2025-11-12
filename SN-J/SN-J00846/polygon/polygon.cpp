/*
祁杨  SN-J00846 西安市曲江第一学校
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 998244353;
long long sum;
long long n;
int a[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	for(int i = 1;i<=n;i++){
		for(int j = i;j<=n;j++){
			if(j-i+1>=3){
				int maxx = -1,num = 0;
				for(int x = i;x<=j;x++){
					num+=a[i];
					maxx = max(maxx,a[x]);
				}
				if(maxx*2<num){
					sum++;
				}
			}
			
		}
	}
	cout<<sum;
	return 0;
}

