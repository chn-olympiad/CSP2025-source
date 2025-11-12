#include<bits/stdc++.h>
using namespace std;

struct newm{
	int j1,j2,j3;
	int t1,loss_t,n1;
	newm(int _j1,int _j2,int _j3){
		j1=_j1;j2=_j2;j3=_j3;
		int sa[3];
		sa[0]=j1;sa[1]=j2;sa[2]=j3;
		int nsa[3]={0,1,2};
		for(int i=0;i<2;i++){
			for(int j=i+1;j<=2-i;j++){
				if(sa[i]<sa[j]){
					int temp=sa[i];
					sa[i]=sa[j];
					sa[j]=temp;
					temp=nsa[i];
					nsa[i]=nsa[j];
					nsa[j]=temp;
				}
			}
		}
		t1=sa[0];loss_t=sa[0]-sa[1];
		n1=nsa[0];		
	}
	newm(){}
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	vector<int>ans(t);
	for(int i=0;i<t;i++){
		int nms;
		scanf("%d",&nms);
		vector<newm>nmems(nms);
		int answ=0;
	vector<int>pkms[3];
	vector<int>lsts[3];
		for(int j=0;j<nms;j++){
			int tmp1,tmp2,tmp3;
			scanf("%d%d%d",&tmp1,&tmp2,&tmp3);
			newm nmb(tmp1,tmp2,tmp3);
			nmems[j]=nmb;
			pkms[nmb.n1].push_back(nmb.t1);
			lsts[nmb.n1].push_back(nmb.loss_t);
			answ+=nmems[j].t1;
		}
		int pickm=-1;
		int cmpr=nms/2;
		for(int i=0;i<3;i++){
			if(cmpr<pkms[i].size()){
				pickm=i;
				break;
			}
		}
		int totalk=0;
		if(pickm!=-1){
			int pms=pkms[pickm].size();
			int topk=pms-cmpr;
			vector<int>pickmems(pms);
			sort(lsts[pickm].begin(),lsts[pickm].end());
			for(int k=0;k<topk;k++){
				totalk+=lsts[pickm][k];
			}
		}
//		cout<<pickm<<endl;
		ans[i]=answ-totalk;
	}
	for(int i=0;i<ans.size();i++)printf("%d\n",ans[i]);
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
