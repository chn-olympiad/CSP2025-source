//41 易琮勋 西安市雁塔区第一学校 

#include<bits/stdc++.h>
using namespace std;

int main(){
	frepoen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int num=10;
	char a,b,c,d,e;
	cin>>a>>b>>c>>d>>e;                                  
	char arr[num]={a,b,c,d,e};
	for(int i=0;i<num;i++){
		if((int)arr[i]>60){
			continue;
		}
		cout<<arr[i];
		
	}
	
	fclose(stdin);
	fclose(stdout);
	
	
	
	
	
	return 0;
}
