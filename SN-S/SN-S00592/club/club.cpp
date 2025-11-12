//肖苏焓 SN-S00592 西安铁一中滨河高级中学 
#include<bits/stdc++.h>
using namespace std;
struct pp{
	long long a;
	long long b;
	long long c;
};
bool cmp(pp x,pp y){
	return x.a>y.a;
}
int d,n,t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
//	cout<<n;
	for(int i=1;i<=n;i++){
		long long sum1[4],summ=0;
		long long m,flag1=1,flag2=1;
		cin>>m;
		int flag[3*m+1];
//		cout<<m<<"$"<<endl;
		pp nn1[3*m+1];
		for(int j=1;j<=3*m;j++){
			cin>>nn1[j].a;
			nn1[j].b=flag1;
			nn1[j].c=flag2;
			flag1++;
			if(flag1>3){
				flag1=1;
				flag2++;
			}
//			cout<<nn1[j].a<<"%"<<nn1[j].b<<"%"<<nn1[j].c<<endl;
		}
		for(int j=1;j<=3*m;j++){
			for(int k=j+1;k<=3*m;k++){
				if(nn1[j].a<nn1[k].a){
					swap(nn1[j],nn1[k]);
				}
			}
		}
//		for(int j=1;j<=3*m;j++){
//			cout<<"*"<<nn1[j].a<<" "<<nn1[j].b<<" "<<nn1[j].c<<" "<<endl;
//		}
		for(int j=1;j<=3*m;j++){
			if(flag[nn1[j].c]!=-1 and sum1[nn1[j].b]<m/2){
				flag[nn1[j].c]=-1;
				sum1[nn1[j].b]++;
//				cout<<nn1[j].a<<"&"<<endl;
				summ=summ+nn1[j].a;
			}
		}
		sum1[1]=0;
		sum1[2]=0;
		sum1[3]=0;
		cout<<summ<<endl;
	}
}
