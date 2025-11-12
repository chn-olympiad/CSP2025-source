//SN-J00042 何沐宸 延安市安塞区高级中学 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string chs,shz;
	cin>>chs;
	int a=chs.size(),b[1000]={0},c=0,max=0;
	if(a=1){
		cout<<chs;
	}else{
		for(int i=0;i<a;i++){
		if('0'<=chs[i]<='9'){
			b[i]+=chs[i];
			c++;	
		}
	}
	}
	
	for(int j=0;j<c;j++){
		if(max<b[j]){
			b[j]=max;	
		cout<<max;
	}
	}
	
	
	return 0;
}
