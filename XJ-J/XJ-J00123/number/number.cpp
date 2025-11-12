#include<bits/stdc++.h>
using namespace std;
int num[1000000];
int s,e=0,f=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=1;i>=0;i++){
		num[i]=s%10;
		s/=10;
		e+=1;
		if(s<=0){
			break;
		}
	}
	for (int i=1;i<=e;i++){
		int ma=0,p;
		for(int j=i;j<=e;j++){
			if(num[j]>ma){
				ma=num[j];
				p=j;
			}
		}
		num[p]=num[i];
		num[i]=ma;
	}
	int ff=e;
	for(int i=1;i<=e;i++){
		f+=num[i]*pow(10,ff-1);
		ff--;
	}
	cout<<f;
	return 0;
}
