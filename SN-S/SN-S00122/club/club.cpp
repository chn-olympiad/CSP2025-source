#include<bits/stdc++.h>
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

int l[100010][3],l1[50010],l2[50010],l3[50010];

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,cnt=0;
		cin>>n;
		int maxn = n/2;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				int x;
				cin>>x;
				l[i][j]=x;
			}
		}
		int a1=0,a2=0,a3=0;
		for(int i=1;i<=n;i++){
			l1[i] = 0;l2[i] = 0;l3[i] = 0;
		}
		for(int i=1;i<=n;i++){
			int x = max(l[i][1],max(l[i][2],l[i][3]));
			if(x==l[i][1]){
				a1++;
				l1[a1] = x; 
			}
			else if(x==l[i][2]){
				a2++;
				l2[a2] = x;
			}
			else{
				a3++;
				l3[a3] = x;
			}
		}
		sort(l1+1,l1+a1+1,cmp);
		sort(l3+1,l3+a3+1,cmp);
		sort(l2+1,l2+a2+1,cmp);
		int s1=0,s2=0,s3=0;
		for(int i=1;i<=maxn;i++){
			cnt+=l1[i];cnt+=l2[i];cnt+=l3[i];
		}
		cout<<cnt<<endl;
	}
	return 0;
}
