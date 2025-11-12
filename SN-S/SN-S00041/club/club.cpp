//SN-S00041 
#include <bits/stdc++.h>
using namespace std;

int t;//测试数据组数 
int n;//新加入成员个数
int a[100005];
int b[100005];
int c[100005];
//a,b,c对应对于三个部门的满意度 

int na,nb,nc;//记录每组人数 

int man;//记录总满意度 
int ba[10];//记录每组满意度 

int nn;

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	
	for(int j=1;j<=t;j++){
	
	
	cin>>n;
	nn=n/2;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>b[i];
		cin>>c[i];
	}//用于输入第i个员工对三个部门的满意度
	
	for(int i=1;i<=n;i++){

		int max=0;//记录第i个员工的最大满意度

		if(a[i]>=b[i]&&a[i]>=c[i]){
			max=a[i];
			na++;	
		}
		if(na>nn) break;
		man=man+max;
	}
//	cout<<man<<endl; 
	for(int i=1;i<=n;i++){

		int max=0;//记录第i个员工的最大满意度

		if(b[i]>c[i]&&b[i]>a[i]){
			max=b[i];
			nb++;	
		}
		if(nb>nn) break;
		man=man+max;
	}
//	cout<<man<<endl; 
	for(int i=1;i<=n;i++){

		int max=0;//记录第i个员工的最大满意度

		if(c[i]>b[i]&&c[i]>a[i]){
		
			max=c[i];
			nc++;	
		}
		if(nc>nn) break;
		man=man+max;
	}
//	cout<<man<<endl; 
	ba[j]=man;
	man=0;
	nn=0;
	na=0;
	nb=0;
	nc=0;
	//cout<<man[j];
	}
	for(int j=1;j<=t;j++){
		cout<<ba[j]<<endl;
	}
	return 0;
}
