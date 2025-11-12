//SN-J00742 王安祺  西安市高新第一学校 
#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int num[1000000];
int cmp(int a,int b){
		return a>b;
}
int gh(int y){
	int nn=1;
	for(int i=1;i<=y;i++){
		nn*=10;
	}
	return nn;
}
int zhuanhuan(int x){
	if(x==48){
		return x=0;
	}
	if(x==49){
		return x=1;
	}
	if(x==50){
		return x=2;
	}
	if(x==51){
		return x=3;
	}
	if(x==52){
		return x=4;
	}
	if(x==53){
		return x=5;
	}
	if(x==54){
		return x=6;
	}
	if(x==55){
		return x=7;
	}
	if(x==56){
		return x=8;
	}
	if(x==57){
		return x=9;
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int n_num=0;
	for (int i=0;i<=a.size();i++){
		if(a[i]=='0'||a[i]=='1'||a[i]=='2'||a[i]=='3'||a[i]=='4'||a[i]=='5'||a[i]=='6'||a[i]=='7'||a[i]=='8'||a[i]=='9'){
			num[n_num]=zhuanhuan(a[i]);
			n_num++;
		}
	}
	sort(num,num+n_num,cmp);
	int nu_num=n_num-1;
	int numberr=0;
	int j=0;
	for(int i=nu_num;i>=0;i--){
		numberr+=num[j]*gh(i);
		j++;
	} 
	cout<<numberr;
	return 0;
} 
