//Sling
//1-club
//Passed_ex 1 2 3 5
//Predict ac_point 17/20
#include<iostream>
#include<cmath>
using namespace std;

const int R = 1e5+10;
int rsize;
long long trans; //Just in case.
struct person{
	int s1,s2,s3,mx; //2e4
}a[R];

void ksort(int r[],int n,int k) {
		//Checkpoint
	//for(int i = 1;i <= n;i++) cout << r[i] << " ";
	//cout << endl;
	if(n <= 1) return;
	int r1[n+2],rm[n+2],r2[n+2];
	int p1 = 0,pm = 0,p2 = 0;
	for(int i = 1;i <= n;i++) {
		if(r[i] < r[(n+1)/2]) r1[++p1] = r[i];
		if(r[i] == r[(n+1)/2]) rm[++pm] = r[i];
		if(r[i] > r[(n+1)/2]) r2[++p2] = r[i];
	}
	ksort(r1,p1,k);
	ksort(r2,p2,k);
	for(int i = 1;i <= p1;i++) r[i] = r1[i];
	for(int i = 1;i <= pm;i++) r[p1+i] = rm[i];
	for(int i = 1;i <= p2;i++) r[p1+pm+i] = r2[i];
	if(n == rsize) for(int i = 1;i <= k;i++) trans -= r[i];
	return;
}

int main() {
	//Access to document
	freopen("club4.in","r",stdin);
	freopen("club4.out","w",stdout);
	int T;
	scanf("%d",&T);
	//cin >> T;
	while(T--) {
		int n; //1e5
		long long maxsat = 0; //Just in case.
		int t1 = 0,t2 = 0,t3 = 0; // <=n/2
		scanf("%d",&n);
		//cin >> n;
		for(int i = 1;i <= n;i++) {
			scanf("%d%d%d",&a[i].s1,&a[i].s2,&a[i].s3);
			//cin >> a[i].s1 >> a[i].s2 >> a[i].s3;
		}
		for(int i = 1;i <= n;i++) {
			bool f1 = a[i].s1 > a[i].s2;
			bool f2 = a[i].s1 > a[i].s3;
			bool f3 = a[i].s2 > a[i].s3;
			if(f1 && f2) t1++,a[i].mx = a[i].s1;
			if(!f1 && f3) t2++,a[i].mx = a[i].s2;
			if(!f2 && !f3) t3++,a[i].mx = a[i].s3;
			maxsat += a[i].mx;
		}
			// Checkpoint
		//cout << maxsat << endl;
		trans = maxsat;
		int r[R],sr = 0;
		if(t1 > n/2) {
			for(int i = 1;i <= n;i++)
				if(a[i].s1 == a[i].mx)
					r[++sr] = a[i].s1 - max(a[i].s2,a[i].s3);
			rsize = t1;
			ksort(r,t1,t1-n/2);
		}
		if(t2 > n/2) {
			for(int i = 1;i <= n;i++)
				if(a[i].s2 == a[i].mx)
					r[++sr] = a[i].s1 - max(a[i].s1,a[i].s3);
			rsize = t2;
			ksort(r,t2,t2-n/2);
		}
		if(t3 > n/2) {
			for(int i = 1;i <= n;i++)
				if(a[i].s3 == a[i].mx)
					r[++sr] = a[i].s3 - max(a[i].s1,a[i].s2);
			rsize = t3;
			ksort(r,t3,t3-n/2);
		}
		maxsat = trans;
		printf("%d\n",maxsat);
		//cout << maxsat << endl;
	}
	return 0;
} 
