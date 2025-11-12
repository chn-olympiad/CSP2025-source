//SN-J00042 何沐宸 延安市安塞区高级中学 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a=0,b=0,c[100]={0},d=0;
	cin>>a>>b;
	for(int i=0;i<a;i++){
		cin>>c[i];
	}
	if(b==0){
		cout<<1;
		return 0;
	}
	for(int j=0;j<a;j++){
			if(c[j]^c[j+1]==b&&c[j+1]!=c[j]){
		d++;	
	}
	}

	cout<<d-(b-1);
	return 0;
}
