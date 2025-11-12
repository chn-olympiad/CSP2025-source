//SN-J00345 张时墉 西安市曲江第一学校
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
int a[1000005];
int ans,cnt;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int j=0;
	while(j<n){
		ans=0;
		j++;
		for(int i=j;i<=n;i++){
			
			ans=(ans^a[i]);
			
			if(ans==k){
				cnt++;
				j=i;
				ans=0;
				continue;
			}
		
		}
	}
	cout<<cnt;
	return 0;

}

