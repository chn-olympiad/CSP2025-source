#include<bits/stdc++.h>
using namespace std;
int t;
struct student{
	int c[5];
	int cha;
	int club1,club2;
}s[100100];
int n,cl[5];
long long total; 
bool cmp(student a,student b){
	return a.cha>b.cha;
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		total=0;
		cl[1]=0,cl[2]=0,cl[3]=0;
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>s[j].c[1]>>s[j].c[2]>>s[j].c[3];
			if(s[j].c[1]>=s[j].c[2]&&s[j].c[1]>=s[j].c[3]){
				s[j].club1=1;
				if(s[j].c[2]>=s[j].c[3])s[j].club2=2;
				else s[j].club2=3;
			}
			else if(s[j].c[2]>=s[j].c[3]){
				s[j].club1=2;
				if(s[j].c[1]>=s[j].c[3])s[j].club2=1;
				else s[j].club2=3;
			}
			else{
				s[j].club1=3;
				if(s[j].c[1]>=s[j].c[2])s[j].club2=1;
				else s[j].club2=2;
			}
			s[j].cha=s[j].c[s[j].club1]-s[j].c[s[j].club2];
		}	
		sort(s+1,s+n+1,cmp);
		for(int j=1;j<=n;j++){
			if(cl[s[j].club1]<n/2){
				cl[s[j].club1]++;
				total+=s[j].c[s[j].club1];
			}
			else{
				cl[s[j].club2]++;
				total+=s[j].c[s[j].club2];
			}
		}
		cout<<total<<endl;
	}
	return 0;
}
