#include<iostream>
#include<algorithm>
using namespace std;
struct f{
	int one,two;
};
int t,n,m,a[100020][3],b[3]={0,0,0},sum[10]={0,0,0,0,0,0,0,0,0,0};
f themin;
bool flag;
int out[3][50010];
f temp;

int main(){
	freopen("club.in","r","stdin");
	freopen("club.out","w","stdout");
	//输入有几组数据 
	cin >> t;
	for(int i=0;i<t;i++){
		//输入这组数据有几人 
		cin >> n;
		m=n/2;
		b[0]=0;
		b[1]=0;
		b[2]=0;
		for(int j=0;j<n;j++){
			//每个人对不同项目的权重 
			cin >> a[j][0] >> a[j][1] >> a[j][2];
			//判断一个人最喜欢什么 
			temp.one=0;
			temp.two=-1;
			for(int k=0;k<=2;k++){
				if(a[j][k]>temp.two){
					temp.one=k;
					temp.two=a[j][k];
				}
			}
			//让一个人尽可能加入他最喜欢的项目
			if(b[temp.one]+1<=m){
			
				//输出数组的【他最喜欢的项目】【他是第几个加入项目的人】=他对此项目的权重 
				out[temp.one][b[temp.one]]=temp.two;
				b[temp.one]+=1;
				sum[i]+=temp.two; 
			}else{
				//查看其他人能否被替代 
				flag=false;
				themin.two=30000;
				for(int k=0;k<b[temp.one];k++){
					if(out[temp.one][k]<=temp.two){
						flag=true;
					}
					if(out[temp.one][k]<themin.two){
						themin.one=k;
						themin.two=out[temp.one][k];
					}
				}
				if(flag){
					for(int k=0;k<2;k++){
						if(k==temp.one){
							continue;
						}else{
							sum[i]+=a[j][k];
						}
					}
					sum[i]-=out[temp.one][themin.one];
					out[temp.one][themin.one]=temp.two;
					sum[i]+=temp.two;
				} 
			} 
	
		}
	}
	//输出 
	for(int i=0;i<t;i++){
		cout << sum[i] << endl;
	}
	return 0;
}
