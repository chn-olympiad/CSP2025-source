#include<bits/stdc++.h>
using namespace std;

struct ren{
	int m1,m2,m3,maxx,minn;
};
ren a[100001];
int cnt[5] = {0,0,0,0,0};

int tanxin1(int max,int min,int pos,int zd){
	if(a[pos].m1 == max&&cnt[1]<zd&&a[pos].m1 != 0){
		cnt[1]++;
		return a[pos].m1;
	}
	if(a[pos].m2 == max&&cnt[2]<zd&&a[pos].m2 != 0){
		cnt[2]++;
		return a[pos].m2;
	}
	if(a[pos].m3 == max&&cnt[3]<zd&&a[pos].m3 != 0){
		cnt[3]++;
		return a[pos].m3;
	}
	else if(a[pos].m1 > a[pos].m2&&cnt[1]<zd&&a[pos].m1 != 0){
		cnt[1]++;
		return a[pos].m1;
	}
	else if(a[pos].m2 > a[pos].m3&&cnt[2]<zd&&a[pos].m2 != 0){
		cnt[2]++;
		return a[pos].m2;
	}
	else if(a[pos].m3 > a[pos].m1&&cnt[3]<zd&&a[pos].m3 != 0){
		cnt[3]++;
		return a[pos].m3;
	}
	else if(a[pos].m1 < a[pos].m2&&cnt[2]<zd&&a[pos].m2 != 0){
		cnt[2]++;
		return a[pos].m2;
	}
	else if(a[pos].m2 < a[pos].m3&&cnt[3]<zd&&a[pos].m3 != 0){
		cnt[3]++;
		return a[pos].m3;
	}
	else if(a[pos].m3 < a[pos].m1&&cnt[1]<zd&&a[pos].m1 != 0){
		cnt[1]++;
		return a[pos].m1;
	}
	else if(a[pos].m1 == min&&a[pos].m1 != 0){
		cnt[1]++;
		return a[pos].m1;
	}
	else if(a[pos].m2 == min&&a[pos].m2 != 0){
		cnt[2]++;
		return a[pos].m2;
	}
	else if(a[pos].m3 == min&&a[pos].m3 != 0){
		cnt[3]++;
		return a[pos].m3;
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,zd,n;
	cin>>t;
	int sum1 = 0;
	int sum2 = 0;

	for(int i = 0;i<t;i++){
		cin>>n;
		zd = n/2;
		sum1 = 0;
		sum2 = 0;
		cnt[1] = 0;cnt[2] = 0;cnt[3] = 0;
		for(int k = 0;k<n;k++){
			cin>>a[k].m1>>a[k].m2>>a[k].m3;
			if(n == 1){
				cout<<max(a[0].m1,max(a[0].m2,a[0].m3));
				return 0;
			}
			a[k].maxx = max(a[k].m1,max(a[k].m2,a[k].m3));
			a[k].minn = min(a[k].m1,min(a[k].m2,a[k].m3));
			sum1+=tanxin1(a[k].maxx,a[k].minn,k,zd);
		}
		cnt[1] = 0;cnt[2] = 0;cnt[3] = 0;
		for(int j = n-1;j>=0;j--){
			cin>>a[j].m1>>a[j].m2>>a[j].m3;
			if(n == 1){
				cout<<max(a[0].m1,max(a[0].m2,a[0].m3));
				return 0;
			}
			a[j].maxx = max(a[j].m1,max(a[j].m2,a[j].m3));
			a[j].minn = min(a[j].m1,min(a[j].m2,a[j].m3));
			sum2+=tanxin1(a[j].maxx,a[j].minn,j,zd);
		}
		cout<<max(sum1,sum2)<<endl;
	}
	return 0;
}
