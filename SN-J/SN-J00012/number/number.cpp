#include<iostream> 
#include<cmath>
#include<string> 
int aaa[10000];
int bbb[10000];
using namespace std;
int main (){
	freopen("number1.in","r",stdin);
	freopen("number1.out","w",stdout);
	int a,b,c;
	long long d,e,f,g,h;
	int aa = 0,ab = 0,ac = 0,ad = 0,ae = 0,af = 0,ag = 0,ah = 0,ai = 0,aj = 0;
	string s;
	cin>>s;
	a = 0;
	b = 0;
	for (int i = 0;i<=1000000;i++){
		
		if (int(s[i]) == 0){
			
			break;
		}
		b+=1;
		if (int(s[i]) >= 48 and int(s[i]) <= 57){
			aaa[i] = int(s[i]);
			
			
		}
		
	}
	for (int i = 0;i<b;i++){
		
		if (aaa[i] == 48){
		
			bbb[i] = 0;
			aa+=1;
			a+=1;
			
		}
		if (aaa[i] == 49){
			
			bbb[i] = 1;
			ab+=1;
			a+=1;
			
		}
		if (aaa[i] == 50){
			
			bbb[i] = 2;
			ac+=1;
			a+=1;
			
		}
		if (aaa[i] == 51){
			
			bbb[i] = 3;
			ad+=1;
			a+=1;
			
		}
		if (aaa[i] == 52){
			
			bbb[i] = 4;
			ae+=1;
			a+=1;
			
		}
		if (aaa[i] == 53){
			
			bbb[i] = 5;
			af+=1;
			a+=1;
			
		}
		if (aaa[i] == 54){
			
			bbb[i] = 6;
			ag+=1;
			a+=1;
			
		}
		if (aaa[i] == 55){
			
			bbb[i] = 7;
			ah+=1;
			a+=1;
			
		}
		if (aaa[i] == 56){
			
			bbb[i] = 8;
			ai+=1;
			a+=1;
			
		}
		if (aaa[i] == 57){
			
			bbb[i] = 9;
			aj+=1;
			a+=1;
			
		}
		
	}
	
	if (aj>=1){
		for (int i = 0;i<aj;i++){
			cout<<9;
		}
	}
	if (ai>=1){
		for (int i = 0;i<ai;i++){
			cout<<8;
		}
	}
	if (ah>=1){
		for (int i = 0;i<ah;i++){
			cout<<7;
		}
	}
	if (ag>=1){
		for (int i = 0;i<ag;i++){
			cout<<6;
		}
	}
	if (af>=1){
		for (int i = 0;i<af;i++){
			cout<<5;
		}
	}
	if (ae>=1){
		for (int i = 0;i<ae;i++){
			cout<<4;
		}
	}
	if (ad>=1){
		for (int i = 0;i<ad;i++){
			cout<<3;
		}
	}
	if (ac>=1){
		for (int i = 0;i<ac;i++){
			cout<<2;
		}
	}
	if (ab>=1){
		for (int i = 0;i<ab;i++){
			cout<<1;
		}
	}
	if (aa>=1){
		for (int i = 0;i<aa;i++){
			cout<<0;
		}
	}
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
