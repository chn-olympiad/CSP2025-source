#include<bits/stdc++.h>
using namespace std;

int nums[600000];
int n, num;
long long k;

long long cpd(int dl, int dr){//计算区间和 
	long long c = nums[dl];
	for(int i = dl+1; i <= dr; i++){
		c = c xor nums[i];
	}
	return c;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	//输入 
	scanf("%d %lld",&n, &k);
	for(int i = 1; i <= n; i++){
		cin >> nums[i];
	}
	
	int l = 1, r = 1;
	while(l<=n){
		if(cpd(l, r) == k){
			num++;
			//printf("[%d,%d] xor = %lld = %lld\n",l,r,cpd(l, r), k); 
			r++;
			l = r;
		}
		else if(r == n){
			l++;
			r = l;
		}
		else{
			r++;
		}
	}
	
	cout << num;
//printf("%d %d %d",1 xor 0, 1 xor 3, 2 xor 4);
	return 0;
}

