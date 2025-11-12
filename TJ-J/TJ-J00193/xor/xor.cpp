#include<bits/stdc++.h>
using namespace std;

int n,k,num[500005],t[500005],ans = 0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i = 1;i <= n;i++){
		scanf("%d",&num[i]);
	}
	int l = 1,r = 1;
	while(r <= n && l <= r){
		int cnt = num[l];
		for(int i = l + 1;i <= r;i++){
			cnt ^= num[i];
		}
		//cout<<l<<" "<<r<<" "<<cnt<<endl;
		if(cnt == k){
			ans++;
			//cout<<1<<" "<<l<<" "<<r<<endl;
			l = r + 1;
			r++;
		}
		else{
			if(r == n) l++;
			else r++;
		}
	//	cout<<l<<" "<<r<<endl;
	}
	printf("%d",ans);
	return 0;
} 
