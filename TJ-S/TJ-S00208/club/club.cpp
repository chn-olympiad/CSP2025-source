#include<bits/stdc++.h>
using namespace std;

const int maxN = 10050;
int t,n;

struct node {
	int x1,x2,x3,num;
} x[maxN];

struct node2 {
	int num,sum;
} y[maxN];

struct node3 {
	int num,sum;
} y2[maxN];

struct node4 {
	int num,sum;
} y3[maxN];

bool cmp1(node2 a,node2 b) {
	return a.sum>b.sum;
}

bool cmp2(node3 a,node3 b) {
	return a.sum>b.sum;
}

bool cmp3(node4 a,node4 b) {
	return a.sum>b.sum;
}

void solve(int n) {
	int temp = 0;
	int maxx = n/2;
	for(int i = 1; i<=n; i++) {
		y[i].num = x[i].num,y[i].sum = x[i].x1;
		y2[i].num = x[i].num,y2[i].sum = x[i].x2;
		y3[i].num = x[i].num,y3[i].sum = x[i].x3;
	}
	sort(y+1,y+n+1,cmp1);
	sort(y2+1,y2+n+1,cmp2);
	sort(y3+1,y3+n+1,cmp3);
	for(int i = 1; i<=maxx; i++) {
		int max1,max2;
		if(y[i].num==y2[i].num) {
			if(y[i].num==y3[i+1].num) {
				max1 = max(y[i].sum+y2[i+1].sum,max(y3[i+1].sum+y[i+2].sum,y3[i+1].sum+y2[i+2].sum));
				max2 = max(y2[i].sum+y[i+2].sum,max(y3[i+1].sum+y[i+2].sum,y3[i+1].sum+y2[i+2].sum));
				if((i+1)>maxx) {
					temp+=(max1>max2?y[i].sum:y3[i+1].sum);
				} else temp+=max(max1,max2);
				continue;
			}
			max1 = max(y[i].sum+y2[i+1].sum,y[i].sum+y3[i].sum);
			max2 = max(y2[i].sum+y[i+1].sum,y2[i].sum+y3[i].sum);
			if((i+1)>maxx) {
				temp+=(max1>max2?y[i].sum:y2[i].sum);
			} else temp+=max(max1,max2);
		} else if(y[i].num == y3[i].num) {
			if(y[i].num==y2[i+1].num) {
				max1 = max(y[i].sum+y3[i+1].sum,max(y2[i+1].sum+y[i+2].sum,y2[i+1].sum+y3[i+2].sum));
				max2 = max(y3[i].sum+y[i+2].sum,max(y2[i+1].sum+y[i+2].sum,y2[i+1].sum+y3[i+2].sum));
				if((i+1)>maxx) {
					temp+=(max1>max2?y[i].sum:y2[i+1].sum);
				} else temp+=max(max1,max2);
				continue;
			}
			max1 = max(y[i].sum+y3[i+1].sum,y[i].sum+y2[i].sum);
			max2 = max(y3[i].sum+y[i+1].sum,y3[i].sum+y2[i].sum);
			if((i+1)>maxx) {
				temp+=(max1>max2?y[i].sum:y3[i].sum);
			} else temp+=max(max1,max2);
		} else if(y2[i].num == y3[i].num) {
			if(y2[i].num==y[i+1].num) {
				max1 = max(y2[i].sum+y3[i+1].sum,max(y[i+1].sum+y2[i+2].sum,y[i+1].sum+y3[i+2].sum));
				max2 = max(y3[i].sum+y2[i+2].sum,max(y[i+1].sum+y2[i+2].sum,y[i+1].sum+y3[i+2].sum));
				if((i+1)>maxx) {
					temp+=(max1>max2?y2[i].sum:y[i+1].sum);
				} else temp+=max(max1,max2);
				continue;
			}
			max1 = max(y2[i].sum+y3[i+1].sum,y2[i].sum+y[i].sum);
			max2 = max(y3[i].sum+y2[i+1].sum,y3[i].sum+y[i].sum);
			if((i+1)>maxx) {
				temp+=(max1>max2?y2[i].sum:y3[i].sum);
			} else temp+=max(max1,max2);
		} else {
			int num1 = y[i].sum+y2[i].sum+y3[i].sum;
			temp+=num1;
		}
	}
	printf("%d\n",temp);
}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.cout","w",stdout);
	scanf("%d",&t);
	for(int k = 1; k<=t; k++) {
		scanf("%d",&n);
		for(int i = 1; i<=n; i++) {
			x[i].x1 = 0,x[i].x2 = 0,x[i].x3 = 0,x[i].num = 0;
		}
		for(int i = 1; i<=n; i++) {
			int a1,a2,a3;
			scanf("%d%d%d",&a1,&a2,&a3);
			x[i].x1 = a1,x[i].x2 = a2,x[i].x3 = a3,x[i].num = i;
		}
		solve(n);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
