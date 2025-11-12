#include<bits/stdc++.h>
using namespace std;

struct m{
//	long long a1;//喜爱程度 废弃 
//	long long a2;
//	long long a3;
	long long f[3][3];//排名 
};
struct s{
	long long l;//喜爱程度 
	long long p;//人数 
//	long long c3;
};


int main(){
//以下基础代码 
    //freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	long long t;
	long long c1;
	long long c2;
	long long c3;
	cin >> t;
	for(int i = 0;i <= t;i++){//总计组数 
		long long n;
		cin >> n;
		m a[t];
		for(int j=0;j < n;j++){//每组输入 
			cin >> a[j].f[0][0] >> a[j].f[0][1] >> a[j].f[0][2];
			a[j].f[1][0] = a[j].f[0][0];//同步 
			a[j].f[1][1] = a[j].f[0][1];
			a[j].f[1][2] = a[j].f[0][2];
		}
//以下排序 
		for(int l = 0;l <= n;l++){//人数 
			for(int p = 0;p <= 3;p++){//次数 
				for(int k = 0;k <= 3;k++){//社团 
			     		if(a[l].f[1][k] < a[l].f[1][k+1]){
					        swap(a[l].f[1][k],a[l].f[1][k+1]);			
					 }
			    }
			}			
	    }
	   // for(int i = 0;i<=t;i++){
    	//for(int j =0;j <= n;j++){
    		cout << a[0].f[1][0] <<" "<< a[0].f[1][1] <<" "<<a[0].f[1][2]<<endl; 
		//}
	//}
	}
	
//分组 计算最大喜爱程度
//输出 
//测试专用
    /*for(int i = 0;i<=t;i++){
    	for(int j =0;j<=n;j++){
    		cout << a[j].f[1][0] <<" "<< a[j].f[1][2] <<" "<<a[j].f[1][2]<<endl; 
		}
	} */
	return 0;
} 
























































