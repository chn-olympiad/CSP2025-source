#include<bits/stdc++.h>
using namespace std;
struct node{
	int to1,to2,to3;
}a[100010];
int n,k;
int people1,people2,people3;
int dfs(int nc,int op){
	if(people1 > k || people2 > k || people3 > k) 
		return 0;
	if(nc == n){
		if(op == 1) return a[nc].to1;
		else if(op == 2) return a[nc].to2;
		else return a[nc].to3;
	}
	int c1 = 0,c2 = 0,c3 = 0;
	if(op == 1){
		people1++;
		c1 = dfs(nc + 1,1);
		people1--;
		people2++;
		c2 = dfs(nc + 1,2);
		people2--;
		people3++;
		c3 = dfs(nc + 1,3);
		people3--;
		if(c1 == -1){
			if(c2 == -1) return c3 + a[nc].to1;
			if(c3 == -1) return c2 + a[nc].to1;
			return max(c2,c3) + a[nc].to1;
		}
		if(c2 == -1){
			if(c3 == -1) return c1 + a[nc].to1;
			return max(c1,c3) + a[nc].to1;
		}
		if(c3 == -1) return max(c1,c2) + a[nc].to1;
		return max(c1,max(c2,c3)) + a[nc].to1;
	}
	if(op == 2){
		people1++;
		c1 = dfs(nc + 1,1);
		people1--;
		people2++;
		c2 = dfs(nc + 1,2);
		people2--;
		people3++;
		c3 = dfs(nc + 1,3);
		people3--;
		if(c1 == -1){
			if(c2 == -1) return c3 + a[nc].to2;
			if(c3 == -1) return c2 + a[nc].to2;
			return max(c2,c3) + a[nc].to2;
		}
		if(c2 == -1){
			if(c3 == -1) return c1 + a[nc].to2;
			return max(c1,c3) + a[nc].to2;
		}
		if(c3 == -1) return max(c1,c2) + a[nc].to2;
		return max(c1,max(c2,c3)) + a[nc].to2;
	}
	if(op == 3){
		people1++;
		c1 = dfs(nc + 1,1);
		people1--;
		people2++;
		c2 = dfs(nc + 1,2);
		people2--;
		people3++;
		c3 = dfs(nc + 1,3);
		people3--;
		if(c1 == -1){
			if(c2 == -1) return c3 + a[nc].to3;
			if(c3 == -1) return c2 + a[nc].to3;
			return max(c2,c3) + a[nc].to3;
		}
		if(c2 == -1){
			if(c3 == -1) return c1 + a[nc].to3;
			return max(c1,c3) + a[nc].to3;
		}
		if(c3 == -1) return max(c1,c2) + a[nc].to3;
		return max(c1,max(c2,c3)) + a[nc].to3;
	}
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 1;i <= n;i++){
			a[i].to1 = 0;
			a[i].to2 = 0;
			a[i].to3 = 0;
		}
		k = n / 2;
		people1 = 0,people2 = 0,people3 = 0;
		for(int i = 1;i <= n;i++)
			cin >> a[i].to1 >> a[i].to2 >> a[i].to3;
		printf("%d\n",max(dfs(1,1),max(dfs(1,2),dfs(1,3))));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
