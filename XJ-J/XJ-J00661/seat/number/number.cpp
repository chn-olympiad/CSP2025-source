#include<bits/stdc++.h>
using namespace std;
int main(){
	int s = ' ';
	int b = 0;
	int num[10000];
	cin>>s;
	if(s == 1||s==2||s==3||s==4||s==5||s==6||s==7||s==8||s==9){
		cout<<s;
	}
	for(int i = num[b];i<=num[s-1];i++){
		if(i%10 == 0 || i%10 == 1 || i%10 == 2 || i%10 == 3 || i%10 == 4 || i%10 == 5 || i%10 == 6 || i%10 == 7 || i%10 == 8 || i%10 == 9){
			int sum;
			if(sum>1000){
				return 0;
			}
		}else{
			break;
		}
	}
	for(int i = 0;i<=s-1;i++){
		int a = num[i];
		if(a%10 == 0 || a%10 == 1 || a%10 == 2 || a%10 == 3 || a%10 == 4 || a%10 == 5 || a%10 == 6 || a%10 == 7 || a%10 == 8 || a%10 == 9){
		    num[b] = a;
		    b+=1;
        }
    }
    int daoxu[100];
    for(int j = num[0];j<=num[b];j++){
    	int maxn = 0;
    	if(j>maxn){
    		maxn = j;
		}
		daoxu[j] = maxn; 
	}
} 
