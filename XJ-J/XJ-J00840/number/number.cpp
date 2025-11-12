#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    int n=0;
    string s;
    cin>>s;
    int lst[1000];
    for(int i=0;i<1000;i++){
    	if((int(s[i])==0)||(int(s[i])==1)||(int(s[i])==2)||(int(s[i])==3)||(int(s[i])==4)||(int(s[i])==5)||(int(s[i])==6)||(int(s[i])==7)||(int(s[i])==8)||(int(s[i])==9)){
    		lst[i]=int(s[i]);
		}
    }
	for (int fuck=0;fuck<1000;fuck++){
		cout<<s[fuck];
	}
    return 0;
}
//#include<bits/stdc++.h>
//using namespace std;
//int main(){
//    freopen("number.in","r",stdin);
//    freopen("number.out","w",stdout);
//
//    string s;
//    cin>>s;
//	int lst=[1,2,3,4,5,6,7,8,9,0];
//	int l[1000010]
//	
//	for(int i=0;i<10;i++){
//		if(char(lst[i])in s){
//			l[i]=lst[i];
//		}
//	}
//	cout<<l;
//
//    return 0;
//}
