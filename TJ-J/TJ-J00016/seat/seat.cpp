#include<iostream>
#include<vector>
using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int m,n,z=0,q,shulie;
	int a[100]; 
	cout<<"请输入行数与列数"<<endl; 
	cin>>n;
	cin>>m;
	cout<<"请输入考生成绩"<<endl;
	for(int i=0;i<=n*m-1;i++)
	{
		cin>>a[i];  
		q=a[0];
	}
	
	for(int i=0;i<=m*n;i++){
	 for(int j=0;j<=i;j++)
		{
			if(a[j+1]<a[j]){
				z=0;
				z=a[j-1];
				a[j-1]=a[j];
				a[j]=z;
				cout<<a[j]<<endl;
			}
		}
	}
	
	for(int i=0;i<=n*m;i++)
	{
		if(a[i]>q){
			shulie+=1;
			}
		
		if(a[0]==q){
			cout<<"第一行第一列"<<endl; 
		}
		if(a[i]%n==0){
			cout<<"第"<<shulie/m<<"行" <<"第"<<shulie/n<<"列";
		}
	}	
	cout<<"第"<<shulie%n<<"行"<<"第"<<shulie/m<<"列"; 
	return 0;
}
