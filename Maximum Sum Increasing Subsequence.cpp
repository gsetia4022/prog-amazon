#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int maxsum(vector<int> &v){
	vector<int> sum(v.size(),0);
	sum[0]=v[0];
	int max;
	for(int i=1;i<v.size();++i){
		int j=i-1;
		max=INT_MIN;
		while(j>=0){
			max=(max<sum[j]&&v[i]>=v[j])?sum[j]:max;
			j--;
		}

		sum[i]=max+v[i];
	}

	max=INT_MIN;
	for(int i=0;i<sum.size();++i){
		cout<<sum[i]<<"  ";
		max=max<sum[i]?sum[i]:max;
	}

	cout<<endl;
	return max;

}



int main(){
int a[]={3, 4, 5, 10};
	vector<int> v(a,a+(sizeof a)/sizeof(int));
	cout<<maxsum(v)<<endl;
	return 0;
}
