#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	
	int n=0;
	int m=0;
	int temp=0;
	cin>>n;
	cin>>m;
	int lst[n][m];
	int sc[n*m];
	for (int i=0;i<n*m;i++){
		cin>>sc[i];
	}
	
	for(int k=0;k<n*n*m*m;k++){			//排序成绩 
		temp=sc[k];
		if(sc[k+1]>sc[k]){
			sc[k]=sc[k+1];
			sc[k+1]=temp;
		}
	}

//以上全是输入与初始化
//以下开始算法部分	
	
	int sum=0;
	int kg=0; 
	int li=0,ha=0;

	for(int r=1;r<=m;r++){
		for(int j=1;j<=n;j++){
			if(ha<n && kg==0){      	//向下走 
				lst[ha][li]=sc[sum]; 
				sum++;
				ha++;
				kg=0;
			}
			if(ha==n && kg==0){        	//走到底部 
				lst[ha][li]=sc[sum];
				li++;
				sum++;
				kg=1;
			}
			
			if(ha==n && kg==1){        	//到底部拐弯 
				lst[ha][li]=sc[sum];
				sum++;
				kg=1;
			}
			if(ha<n && kg==1){			//向上走 
				lst[ha][li]=sc[sum];
				sum++;
				ha--;
				kg=1;
			}
			if(ha==0 && kg==1){			//走到顶部 
				lst[ha][li]=sc[sum];
				li++;
				sum++;
				kg=0;
			}
			if(ha==0 && kg==0){			//到顶部拐弯 
				lst[ha][li]=sc[sum];
				sum++;
				kg=0;
			}
			
			if(sc[sum]==99){			//输出列和行 
				cout<<li+1<<' '<<ha+1;
			}
		}
	}
	
	
    return 0;
}
