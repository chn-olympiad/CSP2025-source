#include<bits/stdc++.h>
using namespace std;
const int N = 1E5+5; 
int n,t,cnt;
int a1,b1,c1;
struct stu{
	int a,b,c;
	char most,second,third;
}stus[N];d
bool cmp(stu s1,stu s2){
	if(s1.a > s2.a){
		return s1.a > s2.a;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int i = 0;i < t;i++){
		cin >> n;
		cnt = 0;
		int n1 = n;
		for(int j = 0;j < n;j++){
			cin >> stus[j].a >> stus[j].b >> stus[j].c;
			if(max(stus[j].a,max(stus[j].b,stus[j].c)) == stus[j].a){
				char most = 'a'; 
				if(stus[j].b > stus[j].c){
					stus[j].second = 'b'; 
				}
				else{
					stus[j].third = 'c'; 
				}
			}
			else if(max(stus[j].a,max(stus[j].b,stus[j].c)) == stus[j].b){
				char most = 'b'; 					
				if(stus[j].a>stus[j].c){
					stus[j].second = 'a'; 
				}
				else{
					stus[j].third = 'c'; 
				}
			}
			else if(max(stus[j].a,max(stus[j].b,stus[j].c)) == stus[j].c){
				char most = 'c';
				if(stus[j].a > stus[j].b){
					stus[j].second = 'a'; 
				}
				else{
					stus[j].third = 'b'; 
				}
			}
		}
		for(int j = 0;j < n;j++){
			if(stus[j].most == 'a'){				
				a1++;
				if(a1 > 0.5*n){
					a1--;
					if(stus[j].second = 'b'){
						b1++;
						if(b1 > 0.5*n){
							b1--;
							cnt += stus[j].c;
						}
					}
					else if(stus[j].second = 'c'){
						c1++;
						if(c1 > 0.5*n){
							c1--;
							cnt += stus[j].b;
						}
					}
				}
				cnt += stus[j].a;
 			}
 			else if(stus[j].most == 'b'){				
				b1++;
				if(b1 > 0.5*n){
					b1--;
					if(stus[j].second = 'a'){
						a1++;
						if(a1 > 0.5*n){
							a1--;
							cnt += stus[j].c;
						}
					}
					else if(stus[j].second = 'c'){
						c1++;
						if(c1 > 0.5*n){
							c1--;
							cnt += stus[j].a;
						}
					}
				}
				cnt += stus[j].b;
 			}
 			else if(stus[j].most == 'c'){				
				c1++;
				if(c1 > 0.5*n){
					c1--;
					if(stus[j].second = 'a'){
						a1++;
						if(a1 > 0.5*n){
							a1--;
							cnt += stus[j].b;
						}
					}
					else if(stus[j].second = 'b'){
						b1++;
						if(b1 > 0.5*n){
							b1--;
							cnt += stus[j].a;
						}
					}
				}
				cnt += stus[j].c;
 			}
 			
 		}
			
	}
	return 0;
}
