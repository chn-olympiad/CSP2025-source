#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("club.in","w",stdin);
	freopen("club.out","r",stdout);
	//n 为偶数
	//不存在一个部门被分配多于n/2个新成员 
	int k;
	cin>>k;
	for(int w=0;w<k;w++){
		int a1[100005]={0},a2[100005]={0},a3[100005]={0};
		bool b1[100005]={0},b2[100005]={0},b3[100005]={0};
		int c1=0,c2=0,c3=0;
		int n,h=0;
		cin>>n;
		int z=n/2;
		for(int i=0;i<n;i++){
			cin>>a1[i];
			cin>>a2[i];
			cin>>a3[i];
			if(a1[i]>a2[i]&&a1[i]>a3[i]){
				if(c1<z){
					c1++;
					b1[i]=1;
				}else{
					if(a1[i])
					a1[i]=0;
				}
			}
			else{
				if(a2[i]>a1[i]&&a2[i]>a3[i]){
					if(c2<z){
						c2++;
						b2[i]=1;
					}else{
						a2[i]=0;
					}	
				}
				else{
					if(c3<z){
						c3++;
						b3[i]=1;
					}else{
						a3[i]=0;
					}
				}
			}
		}
		for(int i=0;i<n;i++){
			if(b1[i]){
				h+=a1[i];
			}
			else{
				if(b2[i]){
					h+=a2[i];
				}else{
					h+=a3[i];
				}
			}
		} 
		cout<<h<<endl;
	}
	//3 4 4 2 1 3 2 4 5 3 4 3 5 1 4 0 1 0 0 1 0 0 2 0 0 2 0 2 10 9 8 4 0 0 
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 
