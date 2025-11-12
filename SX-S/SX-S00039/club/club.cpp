#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,a[N][3],n;
int sum[3];
long long num[3];
int inde[3][N/2]={0};
int m[3];
void ins(long long in,long long pos){
	int pos1=pos;
	while(pos1!=1&&inde[in][pos1]<inde[in][pos1-1]){
		
		swap(inde[in][pos1],inde[in][pos1-1]);
		pos1--;
	}
	return;
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){	
		cin>>n;
		num[1]=0;
		num[2]=0;
		num[3]=0;
		sum[1]=0;
		sum[2]=0;
		sum[3]=0;	
		m[1]=0;
		m[2]=0;
		m[3]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1];
			cin>>a[i][2];
			cin>>a[i][3];	
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				sum[1]++;
				num[1]+=a[i][1];
				m[1]++;
				inde[1][m[1]]=0;
				inde[1][m[1]]=a[i][1]-max(a[i][2],a[i][3]);
				ins(1,m[1]);
			}else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				sum[2]++;
				num[2]+=a[i][2];
				m[2]++;
				inde[2][m[2]]=0;
				inde[2][m[2]]=a[i][2]-max(a[i][1],a[i][3]);
				ins(2,m[2]);
			}else if(a[i][3]>=a[i][2]&&a[i][3]>=a[i][1]){
				int temp=m[3]+1;
				sum[3]++;
				num[3]+=a[i][3];							
				m[3]++;	
				inde[3][m[3]]=0;	
				inde[3][temp]=a[i][3]-max(a[i][2],a[i][1]);	
				while(temp!=1&&inde[3][temp]<inde[3][temp-1]){	
					swap(inde[3][temp],inde[3][temp-1]);
					temp--;
				}
				continue;
			}
		}
		int mx=num[1]+num[2]+num[3];
		if(max(sum[1],max(sum[2],sum[3]))<=n/2){
			cout<<mx<<endl;
			continue;
		}
		int maxn,overn;
		if(sum[1]>sum[2]&&sum[1]>sum[3]){
			maxn=1;
			overn=sum[1]-n/2;
		}else if(sum[2]>sum[1]&&sum[2]>sum[3]){
			maxn=2;
			overn=sum[2]-n/2;
		}else if(sum[3]>sum[2]&&sum[3]>sum[1]){
			maxn=3;
			overn=sum[3]-n/2;
		}
		for(int i=1;i<=overn;i++){
			mx-=inde[maxn][i];
		}
		cout<<mx<<endl;
	}
	return 0;
}
