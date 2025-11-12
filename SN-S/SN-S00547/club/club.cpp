#include<bits/stdc++.h>
using namespace std;
int T,N;
struct node{
	int a1,a2,a3;
}A[100010];
int pai(node n){
	int num1=max(n.a1,n.a2);
	int num2=max(n.a2,n.a3);
	int num3=max(num1,num2);
	if(num3==n.a1)return 1;
	if(num3==n.a2)return 2;
	if(num3==n.a3)return 3;
}
int pai1(node n){
	int num1=max(n.a1,n.a2);
	int num2=max(n.a2,n.a3);
	return max(num1,num2);
}
struct edge{
	int id;int w;
	bool operator<(const edge &b)const{
		return w<b.w;
	}
};
vector<edge>Q1,Q2,Q3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		memset(A,0,sizeof(A));
		Q1.clear();
		Q2.clear();
		Q3.clear();
		cin>>N;
		for(int i=1;i<=N;i++){
			cin>>A[i].a1>>A[i].a2>>A[i].a3;
		}
		for(int i=1;i<=N;i++){
			int id=pai(A[i]);
			if(id==1){
				if(Q1.size()<N/2)Q1.push_back({i,A[i].a1});
				else{
					sort(Q1.begin(),Q1.end());
					int mm=Q1[0].id;
					if(A[i].a1>A[mm].a1){
						A[mm].a1=-1;
						int id2=pai(A[mm]);
						if(id2==2){
							Q2.push_back({mm,A[mm].a2});
						}
						if(id2==3){
							Q3.push_back({mm,A[mm].a3});
						}
						Q1[0]={i,A[i].a1};
					}
					if(A[i].a1==A[mm].a1){
						 node K1=A[i];
						 node K2=A[mm];
						 K1.a1=-1;
						 K2.a1=-1;
						 int num1=pai1(K1);
						 int num2=pai1(K2);
						 if(num2<num1){
						 	int l=pai(K1);
						 	if(l==2)Q2.push_back({i,A[i].a2});
						 	if(l==3)Q3.push_back({i,A[i].a3});
						 	continue;
						 }
						 if(num2>num1){
						 	int l=pai(K2);
						 	if(l==2)Q2.push_back({mm,A[mm].a2});
						 	if(l==3)Q3.push_back({mm,A[mm].a3});
						 	Q1[0]={i,A[i].a1};
						 	continue;
						 }
						 if(num1==num2){
						 	if(pai(K1)==2)Q2.push_back({i,A[i].a2});
						 	if(pai(K1)==3)Q3.push_back({i,A[i].a3});
						 	continue;
						 }
					}
					if(A[i].a1<A[mm].a1){
						A[i].a1=-1;
						int id3=pai(A[i]);
						if(id3==2)Q2.push_back({i,A[i].a2});
						if(id3==3)Q3.push_back({i,A[i].a3});
						continue;
					}
				}
			}
			if(id==2){
				if(Q2.size()<N/2)Q2.push_back({i,A[i].a2});
				else{
					sort(Q2.begin(),Q2.end());
					int mm=Q2[0].id;
					if(A[i].a2>A[mm].a2){
						A[mm].a2=-1;
						int id2=pai(A[mm]);
						if(id2==1){
							Q1.push_back({mm,A[mm].a1});
						}
						if(id2==3){
							Q3.push_back({mm,A[mm].a3});
						}
						Q2[0]={i,A[i].a2};
					}
					if(A[i].a2==A[mm].a2){
						 node K1=A[i];
						 node K2=A[mm];
						 K1.a2=-1;
						 K2.a2=-1;
						 int num1=pai1(K1);
						 int num2=pai1(K2);
						 if(num2<num1){
						 	int l=pai(K1);
						 	if(l==1)Q2.push_back({i,A[i].a1});
						 	if(l==3)Q3.push_back({i,A[i].a3});
						 	continue;
						 }
						 if(num2>num1){
						 	int l=pai(K2);
						 	if(l==1)Q1.push_back({mm,A[mm].a1});
						 	if(l==3)Q3.push_back({mm,A[mm].a3});
						 	Q2[0]={i,A[i].a2};
						 	continue;
						 }
						 if(num1==num2){
						 	if(pai(K1)==1)Q1.push_back({i,A[i].a1});
						 	if(pai(K2)==3)Q3.push_back({i,A[i].a3});
						 	continue;
						 }
					}
					if(A[i].a2<A[mm].a2){
						A[i].a2=-1;
						int id3=pai(A[i]);
						if(id3==1)Q2.push_back({i,A[i].a1});
						if(id3==3)Q3.push_back({i,A[i].a3});
						continue;
					}
				}
			}
			if(id==3){
				if(Q3.size()<N/2)Q3.push_back({i,A[i].a3});
				else{
					sort(Q3.begin(),Q3.end());
					int mm=Q3[0].id;
					if(A[i].a3>A[mm].a3){
						A[mm].a3=-1;
						int id2=pai(A[mm]);
						if(id2==2){
							Q2.push_back({mm,A[mm].a2});
						}
						if(id2==1){
							Q1.push_back({mm,A[mm].a1});
						}
						Q3[0]={i,A[i].a3};
					}
					if(A[i].a3==A[mm].a3){
						 node K1=A[i];
						 node K2=A[mm];
						 K1.a1=-1;
						 K2.a1=-1;
						 int num1=pai1(K1);
						 int num2=pai1(K2);
						 if(num2<num1){
						 	int l=pai(K1);
						 	if(l==1)Q2.push_back({i,A[i].a1});
						 	if(l==2)Q2.push_back({i,A[i].a2});
						 	continue;
						 }
						 if(num2>num1){
						 	int l=pai(K2);
						 	if(l==1)Q1.push_back({mm,A[mm].a1});
						 	if(l==2)Q2.push_back({mm,A[mm].a2});
						 	Q3[0]={i,A[i].a3};
						 	continue;
						 }
						 if(num1==num2){
						 	if(pai(K1)==2)Q2.push_back({i,A[i].a2});
						 	if(pai(K1)==1)Q1.push_back({i,A[i].a1});
						 	continue;
						 }
					}
					if(A[i].a3<A[mm].a3){
						A[i].a3=-1;
						int id3=pai(A[i]);
						if(id3==2)Q2.push_back({i,A[i].a2});
						if(id3==1)Q1.push_back({i,A[i].a1});
						continue;
					}
				}
			}
			//
			
		}
		int ans=0;
		for(int i=0;i<Q1.size();i++){
			ans+=Q1[i].w; 
		}
		for(int i=0;i<Q2.size();i++){
			ans+=Q2[i].w; 
		}
		for(int i=0;i<Q3.size();i++){
			ans+=Q3[i].w; 
		}
		cout<<ans<<endl;
	}
}
