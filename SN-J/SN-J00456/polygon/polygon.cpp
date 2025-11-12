#include<iostream>
using namespace std;
#include<fstream>
//std::ifstream cin(" polygon2.in");std::ofstream cout(" polygon.out");
	


int main(){int n=0;
	int total=0;
	int a[]={0};
	int flag=0;

    //std::ifstream cin(" polygon2.in");std::ofstream cout(" polygon.out");
	
	
	
	cin>>n;
	//cout<<n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}	 
	//cout<<a[1];
	for(int i=1;i<=n;i++){
		total=total+a[1];
	}	 
	
	
	//cout<<total;
	//边数组，总长度
	for(int t=n;t>=3;t--){
		//确认边数量
		int total1=total;
		for(int j=t;j<=n;j++){
			//确认最大边为a[j]
			total1=total1-a[j];
			for(int p=(n-t);p>0;p--){
				//确认减少边个数
				int cut[]={0};
				int hascut=0;
				for(int i=1;i<j;i++){
					int q=0;
					for(int u=1;u<=hascut;u++){
						if(cut[u]==i){
							q++;
						}
					}
					if(q==0){
					total1=total1-a[i]; 
					hascut++;
					cut[hascut]=i;
					
						
					}
				} 
			if((2*a[j]<total1)){
				flag=flag+1;
			}
			} 
	 	
	
		} 
	} 
	cout<<flag;
	
	
	return 0;
}
