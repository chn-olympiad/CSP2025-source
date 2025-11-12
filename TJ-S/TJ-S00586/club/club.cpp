#include<bits/stdc++.h>
using namespace std;
const int M=1e5+10;
int s[4],n;
struct str{
	int x,y,z;
	int num;
}a[M];
bool cmp(str i,str j){
	return i.x>j.x;
}bool cmp2(str i,str j){
	return i.y>j.y;
}bool cmp3(str i,str j){
	return i.z>j.z;
}
void q(int i){
	if(i==1){
		sort(a+1,a+1+n,cmp);
	}else if(i==2){
		sort(a+1,a+1+n,cmp2);
	}else{
		sort(a+1,a+1+n,cmp3);
	}
	return ;
}
long long ans(){
	long long cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i].num==1)cnt+=a[i].x;
		else if(a[i].num==2)cnt+=a[i].y;
		else cnt+=a[i].z;
	}
	return cnt;
}
int main(){
	freopen("club2.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j].x>>a[j].y>>a[j].z;
			if(a[j].x>a[j].y&&a[j].x>a[j].y) {
				a[j].num=1;
				s[1]++;
			}else if(a[j].y>a[j].x&&a[j].y>a[j].z) {
				a[j].num=2;
				s[2]++;
			}else{
				a[j].num=3;
				s[3]++;
			}
		}for(int j=1;j<=3;j++){
			if(s[j]>n/2){
				q(j);
				if(j==1){
					for(int k=n/2+1;k<=n;k++){
						if(a[k].num==1){
							if(a[k].z>a[k].y) a[k].num=3;
							else a[k].num=2;
						} else break; 
					}
				}else if(j==2){
					for(int k=n/2+1;k<=n;k++){
						if(a[k].num==2){
							if(a[k].z>a[k].x) a[k].num=3;
							else a[k].num=1;
						} else break; 
					}
				}else{
					for(int k=n/2+1;k<=n;k++){
						if(a[k].num==3){
							if(a[k].x>a[k].y) a[k].num=1;
							else a[k].num=2;
						} else break; 
					}
				}
			}
		} 
		cout<<ans();
	}
	fclose(stdin);
	fclose(stdout);
} 
