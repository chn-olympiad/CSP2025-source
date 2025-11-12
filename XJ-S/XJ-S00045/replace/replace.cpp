#include <iostream>
#include <string>

using namespace std;
struct twos{
	string s1;
	string s2;
	
};
int n;
twos dic[200010];
int k;

int sol(){//youhuadian2 
	int sum=0;
	string t1,t2;
	cin>>t1>>t2; 
	
	int p=0;
	int l1=t1.length();
	int l2=t2.length();
	if(l1!=l2)return 0;
	string c1,c2;
	for(int i=0;i<n;i++){
		p=0;
		while(t1.find(dic[i].s1,p)!=-1){
			int fd=t1.find(dic[i].s1,p);
			int s2l=dic[i].s2.length();
			if((t1.substr(0,fd)+dic[i].s2+t1.substr(fd+s2l,l1))==t2){
				sum++;
			}
			p=fd+1;
		}
		
		
	}
	
	
	return sum;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		
		cin>>dic[i].s1>>dic[i].s2;
		
	}
	
	for(int i=0;i<k;i++){
		printf("%d\n",sol());
	}
	
	
	
	
	fclose(stdin);
	fclose(stdout);
	
	
	return 0;
}//it could AC 1~5,may AC 6~8,13,14.
