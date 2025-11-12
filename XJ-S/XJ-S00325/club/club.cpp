#include<bits/stdc++.h>
using namespace std;
int t;//1≤t≤ 5
int n;//2≤n≤10^5，且n为偶数
int d[10001][4];//分别表示第 i 个新成员对第 1, 2, 3 个部门的满意度
//判断第i个人的第j个部门是不是他最满意的
bool maxif(int i,int j){
	if(j==1){
		if(d[i][1]>=d[i][2]&&d[i][1]>=d[i][3]) return 1;
	}
	if(j==2){
		if(d[i][2]>=d[i][1]&&d[i][2]>=d[i][3]) return 1;
	}
	if(j==3){
		if(d[i][3]>=d[i][2]&&d[i][3]>=d[i][1]) return 1;
	}
	return 0;
} 
void A(){
	int ans=0;
	for(int i=1;i<=n/2;i++){
		int maxans=0;
		int maxi=0; 
		for(int j=1;j<=n;j++){
			if(d[j][1]>maxans){
				maxans=d[j][1];
				maxi=j;
			}
		}
		d[maxi][1]=0;
		//cout<<maxi<<endl;
		ans+=maxans;
	}
	cout<<ans;
} 
void max_num(){//有a个人  满意度b 
	int r[10001];//第i项表示  第i个人被分配到了第r[i]的部门
	int num[4]; //第[i]个部门已经有num[i]个人了 
	num[2]=0;
	for(int i=1;i<=n;i++){
		
		//判断有没有满员
		if(num[1]<n/2&&maxif(i,1)){
			num[1]++;
			r[i]=1;
			continue;
		}
		if(num[2]<n/2&&maxif(i,2)){
			num[2]++;
			r[i]=2;
			continue;
		}
		if(num[3]<n/2&&maxif(i,3)){
			num[3]++;
			r[i]=3;
			continue;
		}
		//cout<<"第"<<i<<"个人去了第"<<r[i]<<"部门"<<endl;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=d[i][r[i]];
	}cout<<ans<<endl;
	
}
bool fuck(int n1,int n2,int n3,int n4,int n5,int n6,int n7,int n8,int n9,int n10){
	int fuuck[5];
	fuuck[n1]++;
	fuuck[n2]++;
	fuuck[n3]++;
	fuuck[n4]++;
	fuuck[n5]++;
	fuuck[n6]++;
	fuuck[n7]++;
	fuuck[n8]++;
	fuuck[n9]++;
	fuuck[n10]++;
	for(int ii=1;ii<=3;ii++){
		if(fuuck[ii]>5) return 0;
	}return 1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;//输入的第一行包含一个正整数 t，表示测试数据组数
	//接下来依次输入每组测试数据
	for(int cnt=1;cnt<=t;cnt++){//共t组数据  重复执行t次 
		
		int flag=0;
		cin>>n;//第一行包含一个正整数n，表示新成员的数量
		for(int i=1;i<=n;i++){
			cin>>d[i][1]>>d[i][2]>>d[i][3];//第i个队员对每一个部门的满意程度 
			if(d[i][2]!=0||d[i][3]!=0) flag=1;//这一行用来看能不能偷特殊情况A 
		}
		if(n==2){
			int ans2=0;
			for(int s=1;s<=3;s++){
				for(int m=1;m<=3;m++){
					if(m==s) continue;
					ans2=max(ans2,d[1][s]+d[2][m]);
				}
			}
			
			/*if(maxif(1,1)&&maxif(2,1)==0){//第一个人最满意的是1，并且第2个人最满意的不是1 
				//那么满意度就是1对1的满意度+2在2和3里满意度最大的
				cout<<d[1][1]+max(d[2][2],d[2][3]); 
			}else if(maxif(1,2)&&maxif(2,2)==0){
				cout<<d[1][2]+max(d[2][1],d[2][3]); 
			}else if(maxif(1,3)&&maxif(2,3)==0){
				cout<<d[1][2]+max(d[2][1],d[2][3]); 
			}
			*/
			cout<<ans2<<endl;
			continue;
		}
		
		if(n==4){
			int ans4=0;
			for(int s=1;s<=3;s++){
				for(int m=1;m<=3;m++){
					for(int ss=1;ss<=3;ss++){
						for(int mm=1;mm<=3;mm++){
							if(s==m==ss) continue;
							if(s==m==mm) continue;
							if(s==ss==mm) continue;
							if(m==ss==mm) continue;
							ans4=max(ans4,d[1][s]+d[2][m]+d[3][ss]+d[4][mm]);
						}
					}
				}
			}
			cout<<ans4<<endl;
			continue;
		}
		
		if(n==10){
			int ans10=0;
			for(int i1=1;i1<=3;i1++){
				for(int i2=1;i2<=3;i2++){
					for(int i3=1;i3<=3;i3++){
						for(int i4=1;i4<=3;i4++){
							for(int i5=1;i5<=3;i5++){
								for(int i6=1;i6<=3;i6++){
									for(int i7=1;i7<=3;i7++){
										for(int i8=1;i8<=3;i8++){
											for(int i9=1;i9<=3;i9++){
												for(int i10=1;i10<=3;i10++){
													int fuuck[5]={0,0,0,0,0};
													fuuck[i1]++;
													fuuck[i2]++;
													fuuck[i3]++;
													fuuck[i4]++;
													fuuck[i5]++;
													fuuck[i6]++;
													fuuck[i7]++;
													fuuck[i8]++;
													fuuck[i9]++;
													fuuck[i10]++;
													int flagg=0;
													for(int ii=1;ii<=3;ii++){
														if(fuuck[ii]>5) flagg=1;
													}
													if(flagg) continue;
													//cout<<"执行了max语句吗"<<endl; 
													ans10=max(ans10,d[1][i1]+d[2][i2]+d[3][i3]+d[4][i4]+d[5][i5]+d[6][i6]+d[7][i7]+d[8][i8]+d[9][i9]+d[10][i10]);
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			cout<<ans10<<endl;
			continue;
		}
		
		
		//要求出一个最大值  把每个成员分配到各自的部门之后使得这个满意程度最大
		if(flag==0){//说明满足特殊性质A，对2 3都不满意
			//cout<<"AAAAAAAAAAAAAAAAAAA"<<endl;
			A(); 
		}else max_num();
		
	}
	
	return 0;
}
