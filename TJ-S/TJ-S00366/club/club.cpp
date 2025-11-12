#include<bits/stdc++.h>
using namespace std;
struct ren{
	int m1,m2,m3,maxx;
};
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out"£¬"w",stdout);
	ren a[100001];
	int t,zd,n,sum=0,cnt[5]={0,0,0,0,0};
	cin>>t;
	
	for(int i=0;i<t;i++){
		cin>>n;
		zd=n/2;
		sum=0,cnt[1]=0;cnt[2]=0;cnt[3]=0;
		for(int j=0;j<n;j++){
			cin>>a[j].m1>>a[j].m2>>a[j].m3;
			a[j].maxx=max(a[j].m1,max(a[j].m2,a[j].m3));
		}
		for(int j=0;j<n;j++){
			     if(a[j].m1==a[j].maxx&&cnt[1]<=zd){sum+=a[j].maxx;cnt[1]++;}
			else if(a[j].m2==a[j].maxx&&cnt[2]<=zd){sum+=a[j].maxx;cnt[2]++;}
			else if(a[j].m3==a[j].maxx&&cnt[3]<=zd){sum+=a[j].maxx;cnt[3]++;}
			else if(a[j].m1==a[j].maxx&&cnt[1]>zd){sum+=max(a[i].m2,a[i].m3);}
			else if(a[j].m2==a[j].maxx&&cnt[2]>zd){sum+=max(a[i].m1,a[i].m3);}
			else if(a[j].m3==a[j].maxx&&cnt[3]>zd){sum+=max(a[i].m1,a[i].m2);}
		}
		cout<<sum<<endl;
	}
	return 0;
} 
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
