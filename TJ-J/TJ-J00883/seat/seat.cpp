#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a1,a2;
	cin>>a1>>a2;
	int a=a1*a2;
	int ks[114]={};
	for(int i=1;i<=a;i++){
		cin>>ks[i];
	}
	int op=ks[1];
	sort(ks+1,ks+a+1);
    int b[114]={};
    for(int i=1;i<=a;i++){
    	b[i]=ks[a-i+1];
	}
	int cnt=0;
	for(int i=1;i<=a;i++){
		if(b[i]==op){
			cnt=i;
		}
	}

	int couth=cnt/a1;
	
	if(cnt%a1!=0){
		couth++;
	}

	if(couth%2==1){
		if(cnt%a1==0)cout<<couth<<" "<<a1;
		else cout<<couth<<" "<<cnt%a1;
	}
	else{
		if(cnt%a1==0)cout<<couth<<" "<<1;
		else cout<<couth<<" "<<a1+1-cnt%a1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
