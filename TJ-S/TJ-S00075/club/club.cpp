#include<bits/stdc++.h>
using namespace std;
int n;
int t;
struct node{
	int x;
	int y;
	int z;	
}stu[500005];
struct aaa{
	int cnt;
	int sum;
}a1;
aaa a2;
aaa a3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		n=0;
		cin>>n;
		int tans;
		for(int i=1;i<=n;i++){
			cin>>stu[i].x>>stu[i].y>>stu[i].z;
			if(stu[i].x>stu[i].y&&stu[i].x>stu[i].z){
				a1.cnt++;
				if(a1.cnt*2<=n) {
					a1.sum+=stu[i].x;
				
					stu[i].x=-1;
					stu[i].y=-1;
					stu[i].z=-1;	
				}else{
					a1.cnt--;
				}
			}else if(stu[i].y>stu[i].x&&stu[i].y>stu[i].z){
				a2.cnt++;
				if(a2.cnt*2<=n) {
					a2.sum+=stu[i].y;
				
					stu[i].x=-1;
					stu[i].y=-1;
					stu[i].z=-1;	
				}else{
					a2.cnt--;
				}
				
			}else if(stu[i].z>stu[i].x&&stu[i].z>stu[i].y){
				a3.cnt++;
				if(a3.cnt*2<=n) {
					a3.sum+=stu[i].z;
					
					stu[i].x=-1;
					stu[i].y=-1;
					stu[i].z=-1;	
				}else{
					a1.cnt--;
				}
			}
		}
		
		cout<<a1.sum+a2.sum+a3.sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


