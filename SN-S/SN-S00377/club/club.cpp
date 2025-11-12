#include<bits/stdc++.h>
using namespace std;
int t;
int n;
struct student {
	int x,y,z;
	int satis(int n) {
		switch(n) {
			case(1):
				return max(x,max(y,z));
			case(2):
				return x+y+z-max(x,max(y,z))-min(x,min(y,z));
			case(3):
				return min(x,min(y,z));
		}
	}
} a[100001];
bool cmp(student m,student n) {
	return m.satis(1)-m.satis(2)>n.satis(1)-n.satis(2);
}
int Sum(int num) {
	long long sum=0;
	int c1=0,c2=0,c3=0;
	for(int i=0; i<n; i++) {
		sort(a,a+n,cmp);
		if(a[i].x==a[i].satis(1)&&c1<num) {
			sum+=a[i].satis(1),c1++;
			continue;
		} else if(a[i].y==a[i].satis(1)&&c2<num) {
			sum+=a[i].satis(1),c2++;
			continue;
		} else if(a[i].z==a[i].satis(1)&&c3<num) {
			sum+=a[i].satis(1),c3++;
			continue;
		} else {
			if(a[i].x==a[i].satis(2)&&c1<num) {
				sum+=a[i].satis(2),c1++;
				continue;
			} else if(a[i].y==a[i].satis(2)&&c2<num) {
				sum+=a[i].satis(2),c2++;
				continue;
			} else if(a[i].z==a[i].satis(2)&&c3<num) {
				sum+=a[i].satis(2),c3++;
				continue;
			} else {
				if(a[i].x==a[i].satis(3)&&c1<num) {
					sum+=a[i].satis(3),c1++;
					continue;
				} else if(a[i].y==a[i].satis(3)&&c2<num) {
					sum+=a[i].satis(3),c2++;
					continue;
				} else if(a[i].z==a[i].satis(3)&&c3<num) {
					sum+=a[i].satis(3),c3++;
					continue;
				}
			}
		}
	}
	return sum;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		memset(a,0,sizeof(a));
		cin>>n;
		int num=n/2,ans=0;
		for(int i=0; i<n; i++)
			cin>>a[i].x>>a[i].y>>a[i].z;
		cout<<Sum(num)<<endl;
	}
	return 0;
}

