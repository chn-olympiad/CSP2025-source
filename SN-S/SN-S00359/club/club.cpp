#include<bits/stdc++.h>
using namespace std;
int aa[5]={0},num=0,a[200005][5]={0},m=0;
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//void sr(int z){
//	for(int i=1;i<=z;i++){
//		cin>>a[i][1]>>a[i][2]>>a[i][3];
//	}
//}
//int dis(int x,int y){
//	if(x>y){
//		return 0;
//	}
//	int b=0,c=0,d=0,e=0,maxx=0,minx=0;
//	d=min(a[x][1],a[x][2]);
//	e=min(a[x][2],a[x][3]);
//	minx=min(e,d);
//	if(a[x][1]==minx&&aa[2]==y/2&&aa[3]==y/2){
//		aa[1]++;
//		num+=minx;
//		dis(x+1,y);
//	}
//	if(a[x][2]==minx&&aa[1]==y/2&&aa[3]==y/2){
//		aa[2]++;
//		num+=minx;
//		dis(x+1,y);
//	}
//	if(a[x][3]==minx&&aa[2]==y/2&&aa[1]==y/2){
//		aa[3]++;
//		num+=minx;
//		dis(x+1,y);
//	}
//}
//int dir(int x,int y){
//	if(x>y){
//		return 0;
//	}
//	int b=0,c=0,d=0,e=0,maxx=0,minx=0;
//	b=max(a[x][1],a[x][2]);
//	c=max(a[x][2],a[x][3]);
//	d=min(a[x][1],a[x][2]);
//	e=min(a[x][2],a[x][3]);
//	maxx=max(b,c);
//	minx=min(e,d);
//	if(a[x][1]!=minx&&a[x][1]!=maxx&&(aa[2]==y/2||aa[3]==y/2)){
//		aa[1]++;
//		num+=a[x][1]+a[x][2]+a[x][3]-maxx-minx;
//		dir(x+1,y);
//	}
//	else if(a[x][1]!=minx&&a[x][1]!=maxx&&aa[1]==y/2){
//		dis(x,y);
//	}
//	if(a[x][2]!=minx&&a[x][2]!=maxx&&(aa[1]==y/2||aa[3]==y/2)){
//		aa[2]++;
//		num+=a[x][1]+a[x][2]+a[x][3]-maxx-minx;
//		dir(x+1,y);
//	}
//	else if(a[x][2]!=minx&&a[x][2]!=maxx&&aa[2]==y/2){
//		dis(x,y);
//	}
//	if(a[x][3]!=minx&&a[x][3]!=maxx&&(aa[2]==y/2||aa[1]==y/2)){
//		aa[3]++;
//		num+=a[x][1]+a[x][2]+a[x][3]-maxx-minx;
//		dir(x+1,y);
//	}
//	else if(a[x][3]!=minx&&a[x][3]!=maxx&&aa[3]==y/2){
//		dis(x,y);
//	}
//}
//int diy(int x,int y){
//	if(x>y){
//		return 0;
//	}
//	int b=0,c=0,d=0,e=0,maxx=0,minx=0;
//	b=max(a[x][1],a[x][2]);
//	c=max(a[x][2],a[x][3]);
//	maxx=max(b,c);
////	cout<<maxx<<" ";
//	if(a[x][1]==maxx&&aa[1]<y/2){
//		aa[1]++;
//		num+=maxx;
//		cout<<num<<" ";
//		diy(x+1,y);
//	}
//	else if(a[x][1]==maxx&&aa[1]==y/2){
//		dir(x,y);
//	}
//	if(a[x][2]==maxx&&aa[2]<y/2){
//		aa[2]++;
//		num+=maxx;
//		
//		diy(x+1,y);
//	}
//	else if(a[x][2]==maxx&&aa[2]==y/2){
//		dir(x,y);
//	}
//	if(a[x][3]==maxx&&aa[3]<y/2){
//		aa[3]++;
//		num+=maxx;
//		diy(x+1,y);
//	}
//	else if(a[x][3]==maxx&&aa[3]==y/2){
//		dir(x,y);
//	}
//	return num;
//}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,t,nn[3]={0},nnn[200005]={0};
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		int m=0;
		for(int j=1;j<=n;j++){
			cin>>a[j][1]>>a[j][2]>>a[j][3];
		}
		int b=a[1][1]+a[2][2];
		int c=a[1][1]+a[2][3];
		int d=a[1][2]+a[2][1];
		int e=a[1][2]+a[2][3];
		int f=a[1][3]+a[2][1];
		int g=a[1][3]+a[2][2];
		nn[i]=max(b,max(c,max(d,max(e,max(f,g)))));
//		sr(n);
//		num=0;
//		diy(1,n);
//		int b=num;
//		num=0;
//		diy(2,n);
//		int c=num+a[1][2];
//		cout<<num<<a[1][2];
//		num=0;
//		diy(2,n);
//		int d=num+a[1][3];
//		nnn[i]=max(b,max(c,d));
	}
	for(int i=1;i<=t;i++){
		cout<<nn[i];		
		if(i!=t){
			cout<<endl;
		}
	}
//	cout<<nn[1]<<endl<<nn[2];
	return 0;
}
//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0

