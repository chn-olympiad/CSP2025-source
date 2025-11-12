#include<iostream>
#include<algorithm>
using namespace std;
/* 
//////////////////////////////////////////////////
__________________________________________________
			 /|\		
			/ |	\	
		   /  |	 \	
		  /	  |	  \	
		 /	  |	   \	
		/	  |     \
	入射光线 法线f  反射光线 
		i		       r
入射角等于反射角
法线垂直于反射面
法线平分入射光线和反射光线的夹角  

三角形三边关系: 两边之和大于第三边,两边之差小于第三边 
*/
int n;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(a[1]+a[2]>a[3] && a[2]-a[1]<a[3]){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
