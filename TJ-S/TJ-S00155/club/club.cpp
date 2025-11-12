#include<bits/stdc++.h>
using namespace std;
int n,sum;
struct member{
    int id;
    int a1;
    int a2;
    int a3;
}p[100005];
struct club{
	int num;
	int value;
};
vector<club> c1,c2,c3;

//排序比较方法 -> 增加兴趣值max-减去兴趣值 由低到高排 
bool cmp1(club x,club y){
	int yuanx=x.value,yuany=y.value; //减少的兴趣值
	int zx=max(p[x.num].a2,p[x.num].a3),zy=max(p[y.num].a2,p[y.num].a3); //增加的最多兴趣值 
	int cx=zx-yuanx,cy=zy-yuany;
	return cx<=cy;
}

bool cmp2(club x,club y){
	int yuanx=x.value,yuany=y.value; //减少的兴趣值
	int zx=max(p[x.num].a1,p[x.num].a3),zy=max(p[y.num].a1,p[y.num].a3); //增加的最多兴趣值 
	int cx=zx-yuanx,cy=zy-yuany;
	return cx<=cy;
}

bool cmp3(club x,club y){
	int yuanx=x.value,yuany=y.value; //减少的兴趣值
	int zx=max(p[x.num].a1,p[x.num].a2),zy=max(p[y.num].a1,p[y.num].a2); //增加的最多兴趣值 
	int cx=zx-yuanx,cy=zy-yuany;
	return cx<=cy;
}


int add(){ //计算兴趣和 
	int sum=0;
	for(int i=0;i<max(max(c1.size(),c2.size()),c3.size());i++){
		if(i<c1.size()) sum+=c1[i].value;
		if(i<c2.size()) sum+=c2[i].value;
		if(i<c3.size()) sum+=c3[i].value;
	} 
	return sum;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    int t;
    cin>>t;
    while(t--){
        cin>>n;
        sum=0;
        for(int i=1;i<=n;i++){
            p[i].id=i;
            cin>>p[i].a1>>p[i].a2>>p[i].a3;
            
            club qwq;qwq.num=p[i].id;
            if(p[i].a1>=p[i].a2){
            	if(p[i].a1>=p[i].a3){
            		qwq.value=p[i].a1;
            		c1.push_back(qwq);
				}else{
					qwq.value=p[i].a3;
					c3.push_back(qwq);
				}
			}else{
				if(p[i].a2>=p[i].a3){
					qwq.value=p[i].a2;
            		c2.push_back(qwq);
				}else{
					qwq.value=p[i].a3;
					c3.push_back(qwq);
				}
			}
		}
		
        int m=n/2; //超限限制n/2 
        
        //对应三种社团全部符合 
        if(c1.size()<=m && c2.size()<=m && c3.size()<=m){
        	//符合
			sum=add();
			cout<<sum;
			c1.clear();c2.clear();c3.clear();
			continue;
		}
		
		//对应特殊性质AB及普通情况 
		if(c1.size()>m){
			sort(c1.begin(),c1.end(),cmp1); //对序列排序，使在对应兴趣减少最小的同时，对其他社团的兴趣和最大
//			for(int i=0;i<c1.size();i++){
//				cout<<c1[i].num<<" "<<c1[i].value<<" "<<p[c1[i].num].a2<<" "<<p[c1[i].num].a3;
//				cout<<endl;
//			}cout<<endl;
			while(c1.size()>m){ //将对兴趣值影响最少的人放在其他社团 
				if(p[c1.back().num].a2>=p[c1.back().num].a3 && c2.size()+1<=m){
					c1.back().value=p[c1.back().num].a2;
					c2.push_back(c1.back());
					c1.pop_back();
				}else{
					c1.back().value=p[c1.back().num].a3;
					c3.push_back(c1.back());
					c1.pop_back();
				}
			}
//			print();
			sum=add();
			cout<<sum;
			c1.clear();c2.clear();c3.clear();
			continue;
		}else if(c2.size()>m){
			sort(c2.begin(),c2.end(),cmp2); //对序列排序，使在对应兴趣减少最小的同时，对其他社团的兴趣和最大
//			for(int i=0;i<c2.size();i++){
//				cout<<c2[i].num<<" "<<c2[i].value<<" "<<p[c2[i].num].a1<<" "<<p[c2[i].num].a3;
//				cout<<endl;
//			}cout<<endl;
			while(c2.size()>m){ //将对兴趣值影响最少的人放在其他社团 
				if(p[c2.back().num].a1>=p[c2.back().num].a3 && c1.size()+1<=m){
					c2.back().value=p[c2.back().num].a1;
					c1.push_back(c2.back());
					c2.pop_back();
				}else{
					c2.back().value=p[c2.back().num].a3;
					c3.push_back(c2.back());
					c2.pop_back();
				}
			}
//			print();
			sum=add();
			cout<<sum;
			c1.clear();c2.clear();c3.clear();
			continue;
		}else if(c3.size()>m){
			sort(c3.begin(),c3.end(),cmp3); //对序列排序，使在对应兴趣减少最小的同时，对其他社团的兴趣和最大
//			for(int i=0;i<c3.size();i++){
//				cout<<c3[i].num<<" "<<c3[i].value<<" "<<p[c3[i].num].a1<<" "<<p[c3[i].num].a2;
//				cout<<endl;
//			}cout<<endl;
			while(c3.size()>m){ //将对兴趣值影响最少的人放在其他社团 
				if(p[c3.back().num].a1>=p[c3.back().num].a2 && c1.size()+1<=m){
					c3.back().value=p[c3.back().num].a1;
					c1.push_back(c3.back());
					c3.pop_back();
				}else{
					c3.back().value=p[c3.back().num].a2;
					c2.push_back(c3.back());
					c3.pop_back();
				}
			}
//			print();
			sum=add();
			cout<<sum;
			c1.clear();c2.clear();c3.clear();
			continue;
		}
	}
	return 0;
}

