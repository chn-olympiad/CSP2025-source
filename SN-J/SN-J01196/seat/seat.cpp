/*
CSP-J 
姓名：魏诺澜
准考证号：SN-J01196
学校：西北工业大学附属中学 
*/ 
#include<bits/stdc++.h>
using namespace std;
int n,m;
int s[110];
int cnt;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
	}
	cnt=s[1];
	sort(s+1,s+1+n*m,cmp);
	int x;
	for(int i=1;i<=n*m;i++){
		if(s[i]==cnt){
			x=i;
			break;
		}
	}
	int chu=x/n;
	int quyu=x%n;
	if(quyu>0){
		chu++;
	}
	cout<<chu<<" ";
	if(chu%2!=0){
		if(quyu==0)quyu=n;
		cout<<quyu;
	}else{
		if(quyu==0)cout<<1;
		else cout<<quyu+n-1;
	}
	return 0;
}
