#include<bits/stdc++.h>
using namespace std;
int main(){
	
	int t;
	cin>>t;
	int allmyd[t]={};
	for(int i=1;i<=t;i++){
		int n=0;
		cin>>n;
		int bm1[2][n];
		int bm2[2][n];
		int bm3[2][n];
		for(int j=0;j<n;j++){
			bm1[0][j]=j;
			bm2[0][j]=j;
			bm3[0][j]=j;
			cin>>bm1[1][j];
			cin>>bm2[1][j];
			cin>>bm3[1][j];
		}//分别输入n个人对三个部门的满意度
		for(int j=0;j<n-1;j++){
			int a=0;
			for(int k=0;k<n-1;k++){
				if(bm1[1][k]<bm1[1][k+1]){
					swap(bm1[0][k],bm1[0][k+1]);
					swap(bm1[1][k],bm1[1][k+1]);
					a++;
				}
			}
			if(a==0){
				break;
			}
		}//n个人对部门1的满意度按升序排列 
		for(int j=0;j<n-1;j++){
			int a=0;
			for(int k=0;k<n-1;k++){
				if(bm2[1][k]<bm2[1][k+1]){
					swap(bm2[0][k],bm2[0][k+1]);
					swap(bm2[1][k],bm2[1][k+1]);
					a++; 
				}
			}
			if(a==0){
				break;
			}
		}//n个人对部门2的满意度按升序冒泡排序 
		for(int j=0;j<n-1;j++){
			int a=0;
			for(int k=0;k<n-1;k++){
				if(bm3[1][k]<bm3[1][k+1]){
					swap(bm3[0][k],bm3[0][k+1]);
					swap(bm3[1][k],bm3[1][k+1]);
					a++; 
				}
			}
			if(a==0){
				break;
			}
		}//n个人对部门3的满意度按升序排列
		int sum[2][n/2*3];
		for(int k=0;k<n/2;k++){
			sum[0][k]=bm1[0][k];
			sum[1][k]=bm1[1][k];
		}
		for(int k=n/2;k<n;k++){
			sum[0][k]=bm2[0][k-n/2];
			sum[1][k]=bm2[1][k-n/2];
		}
		for(int k=n;k<n/2*3;k++){
			sum[0][k]=bm3[0][k-n];
			sum[1][k]=bm3[1][k-n];
		}//3个部门满意度前1/2的人的序号和满意度输入sum[n/2*3][2]数组
		for(int j=0;j<n/2*3;j++){
			for(int k=0;j<n/2*3;j++){
				if(sum[1][k]<sum[1][k+1]){
					swap(sum[0][k],sum[0][k+1]);
					swap(sum[1][k],sum[1][k+1]);
				} 
			}
		}//sum[n/2*3][2]数组中的人的满意度按升序排列 
		for(int j=0;j<n/2*3;j++){
			cout<<sum[1][j]<<" ";
		}
		int ans[n]={};
		for(int j=0;j<n/2*3;j++){
			if(ans[sum[0][j]]==0){
				allmyd[i]+=sum[1][j];
				ans[sum[0][j]]++;
			}
		}
	}
	for(int j=0;j<t;j++){
		cout<<allmyd[j];
	}
	
	return 0;
}
