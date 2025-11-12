#include<fstream>
std::ifstream cin("number.in");
std::ofstream cout("number.out");
int main(){
	char n[1000005]={};
	int a=0,n2[100005]={0},m=0,m2=0;
	cin>>n;
//	0 A a
// 48 65 97
	for(int i=0;i<1000005;i++){
		if(n[i]=='0' or n[i]=='1' or n[i]=='2' or n[i]=='3' or n[i]=='4' or n[i]=='5' or n[i]=='6' or n[i]=='7' or n[i]=='8' or n[i]=='9'){
			a++;
			n2[a]=n[i]-48;
			
		}else if(n[i]==' '){
			break;
		}
	}	
	int p=0;
	for(int i=0;i<;i++){
		if(n2[i]<n2[i+1]){
			p=n2[i];
			n2[i]=n2[i+1];
			n2[i+1]=p;	
		}
	}
	for(int i=0;i<a;i++){
		cout<<n2[i];
	}
	return 0;
} 
