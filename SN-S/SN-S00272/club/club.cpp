#include<bits/stdc++.h>
using namespace std;
struct sc{
	int a;
	int b;
	int c;
};
struct sa{
	int my;//满意度 
	int d;//部门
	int p;//第p个人 
};
bool cp(sa a1,sa b1){
	return a1.my<b1.my;
}
int T,pass[100005];
sc s[100005];
sa s1[100005],s2[100005],s3[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		int n,ans1=0,ans2=0,ans3=0,ct1=0,ct2=0,ct3=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
		}
		for(int i=0;i<n;i++){
			//1
			if(s[i].a>=s[i].b && s[i].a>=s[i].c){
				s1[i].my=s[i].a;
				s1[i].d=1;
				s1[i].p=i;
			}else if(s[i].b>=s[i].a && s[i].b>=s[i].c){
				s1[i].my=s[i].b;
				s1[i].d=2;
				s1[i].p=i;
			}else if(s[i].c>=s[i].a && s[i].c>=s[i].b){
				s1[i].my=s[i].c;
				s1[i].d=3;
				s1[i].p=i;
			}
			//2
			if(s[i].a<=s[i].b && s[i].a>=s[i].c){
				s2[i].my=s[i].a;
				s2[i].d=1;
				s2[i].p=i;
			}else if(s[i].b<=s[i].a && s[i].b>=s[i].c){
				s2[i].my=s[i].b;
				s2[i].d=2;
				s2[i].p=i;
			}else if(s[i].c<=s[i].a && s[i].c>=s[i].b){
				s2[i].my=s[i].b;
				s2[i].d=2;
				s2[i].p=i;
			}
			//3
			if(s[i].a<=s[i].b && s[i].a<=s[i].c){
				s3[i].my=s[i].a;
				s3[i].d=1;
				s3[i].p=i;
			}else if(s[i].b<=s[i].a && s[i].b<=s[i].c){
				s3[i].my=s[i].b;
				s3[i].d=2;
				s3[i].p=i;
			}else if(s[i].c<=s[i].a && s[i].c<=s[i].b){
				s3[i].my=s[i].c;
				s3[i].d=3;
				s3[i].p=i;
			}
		}
		memset(s1,s1+100005,cp);
		memset(s2,s2+100005,cp);
		memset(s3,s3+100005,cp);
		for(int i=0;i<n;i++){
			if(s1[i].d==1 && pass[s1[i].p-1]==0 && ct1<=n/2){
				ans1+=s1[i].my;
				pass[s1[i].p-1]=1;
				ct1++;
			}else if(s1[i].d==2 && pass[s1[i].p-1]==0 && ct2<=n/2){
				ans2+=s1[i].my;
				pass[s1[i].p-1]=1;
				ct2++;
			}else if(s1[i].d==3 && pass[s1[i].p-1]==0 && ct3<=n/2){
				ans3+=s1[i].my;
				pass[s1[i].p-1]=1;
				ct3++;
			}
			if(s2[i].d==1 && pass[s2[i].p-1]==0 && ct1<=n/2){
				ans2+=s2[i].my;
				pass[s2[i].p-1]=1;
				ct1++;
			}else if(s2[i].d==2 && pass[s2[i].p-1]==0 && ct2<=n/2){
				ans2+=s2[i].my;
				pass[s2[i].p-1]=1;
				ct2++;
			}else if(s2[i].d==3 && pass[s2[i].p-1]==0 && ct3<=n/2){
				ans3+=s2[i].my;
				pass[s2[i].p-1]=1;
				ct3++;
			}
			if(s3[i].d==1 && pass[s3[i].p-1]==0 && ct1<=n/2){
				ans3+=s3[i].my;
				pass[s3[i].p-1]=1;
				ct1++;
			}else if(s3[i].d==2 && pass[s3[i].p-1]==0 && ct2<=n/2){
				ans2+=s3[i].my;
				pass[s3[i].p-1]=1;
				ct2++;
			}else if(s3[i].d==3 && pass[s3[i].p-1]==0 && ct3<=n/2){
				ans3+=s3[i].my;
				pass[s3[i].p-1]=1;
				ct3++;
			}
		}
		cout<<ans1+ans2+ans3;
	}
	return 0;
}
