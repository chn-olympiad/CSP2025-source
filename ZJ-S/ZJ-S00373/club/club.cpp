#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long
int Test,Maxx;
int Number;
struct node{
	int n1,n2,n3;
	int cha;
}cnt[100005];
bool cmp(node n1,node n2){
	return n1.cha<n2.cha;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>Test;
	while(Test--){
		int Ans=0;
		vector<node> ve1,ve2,ve3;
		cin>>Number;
		for(int i=1;i<=Number;i++){
			scanf("%d %d %d",&cnt[i].n1,&cnt[i].n2,&cnt[i].n3);
			int m1=cnt[i].n1,m2=cnt[i].n2,m3=cnt[i].n3;
			if(m1>=m2 && m1>=m3){
				if(m2>m3) cnt[i].cha=m1-m2;
				else cnt[i].cha=m1-m3;
				ve1.push_back(cnt[i]); 
				Ans+=m1;
			}
			else if(m2>=m1 && m2>=m3){
				if(m1>m3) cnt[i].cha=m2-m1;
				else cnt[i].cha=m2-m3;
				ve2.push_back(cnt[i]); 
				Ans+=m2;
			}
			else{
				if(m1>m2) cnt[i].cha=m3-m1;
				else cnt[i].cha=m3-m2;
				ve3.push_back(cnt[i]); 
				Ans+=m3;
			}
		}
		if(ve1.size()>(Number/2)){
			int s1=ve1.size();
			sort(ve1.begin(),ve1.end(),cmp);
			for(int i=0;i<s1-(Number/2);i++)
				Ans-=ve1[i].cha;
		}
		else if(ve2.size()>(Number/2)){
			int s2=ve2.size();
			sort(ve2.begin(),ve2.end(),cmp);
			for(int i=0;i<s2-(Number/2);i++)
				Ans-=ve2[i].cha;
		}
		else{
			int s3=ve3.size();
			sort(ve3.begin(),ve3.end(),cmp);
			for(int i=0;i<s3-(Number/2);i++)
				Ans-=ve3[i].cha;
		}
		printf("%d\n",Ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
