#include <bits/stdc++.h>
using namespace std;


int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		long long a[n][4][2]={0},maxx[n]={0};
		long long para[n][6];
		for(long long i=0;i<n;i++){
			long long tmp[3][2];
			cin>>tmp[0][1]>>tmp[1][1]>>tmp[2][1];
			tmp[0][0]=0,tmp[1][0]=1,tmp[2][0]=2;
			for(int j=0;j<3;j++){
				for(int k=j;k<3;k++)
					if(tmp[j][1]>tmp[k][1]){
						swap(tmp[j],tmp[k]);		
					}
			}
			a[i][0][0]=tmp[0][0],a[i][0][1]=tmp[0][1];
			a[i][1][0]=tmp[1][0],a[i][1][1]=tmp[1][1];
			a[i][2][0]=tmp[2][0],a[i][2][1]=tmp[2][1];
			a[i][3][0]=i;
			//a[i][2][0]是一志愿，a[i][2][1]是分数 
//			for(int j=0;j<3;j++)
//				cout<<a[i][j][0]<<"部门"<<a[i][j][1]<<"分数"<<endl; 
		}
		
		
		long long sum[3]={0};
		long long manyi=0;
		bool used[n]={false};
		//排序 
		for(long long i=0;i<n;i++){
			for(long long j=i+1;j<n;j++){
				if(a[i][2][1]<a[j][2][1]){
					swap(a[i],a[j]);
					continue;
				}
			}
		}
		//录取一志愿 
		for(long long i=0;i<n;i++){
			if(sum[a[i][2][0]]<n/2){
				sum[a[i][2][0]]++,manyi+=a[i][2][1],used[a[i][3][0]]=true;
				//cout<<i<<"被一志愿以"<<a[i][2][1]<<"分"<<endl; 
			}
		}
		//排序 
		for(long long i=0;i<n;i++){
			if(used[a[i][3][0]])
				continue;
			for(long long j=i+1;j<n;j++){
				if(used[a[j][3][0]])
					continue;
				if(a[i][1][1]<a[j][1][1]){
					swap(a[i],a[j]);
					continue;
				}
			}
		}
		//录取二志愿 
		for(long long i=0;i<n;i++){
			if(!used[a[i][3][0]]&&sum[a[i][1][0]]<n/2)
				sum[a[i][1][0]]++,manyi+=a[i][1][1],used[a[i][3][0]]=true;
		}	
		//排序 
		for(long long i=0;i<n;i++){
			if(used[a[i][3][0]])
				continue;
			for(long long j=i+1;j<n;j++){
				if(used[a[j][3][0]])
					continue;
				if(a[i][0][1]<a[j][0][1]){
					swap(a[i],a[j]);
					continue;
				}
			}
		}
		//录取三志愿 
		for(long long i=0;i<n;i++){
			if(!used[a[i][3][0]]&&sum[a[i][1][0]]<n/2)
				sum[a[i][1][0]]++,manyi+=a[i][1][1],used[a[i][3][0]]=true;
		}
		
		//打印
		cout<<manyi<<endl; 
	}
	return 0;
}
