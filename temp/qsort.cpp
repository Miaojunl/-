#include<iostream>
using namespace std;
void qsort(int *a,int low, int high){
	if(low>=high) return;
	int first=low;
	int last=high;
	int key=a[first];
	while(first<last){
		while(a[last]>key && last>first ){
			--last;
		}
		a[first]=a[last];
		while(a[first]<=key && first<last){
			++first;
		}
		a[last]=a[first];
	}
	a[first]=key;
	qsort(a,low,first-1);
	qsort(a,first+1,high);
}

void selectsort(int *a,int n){
	int tmp;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]>a[j]){
				tmp=a[i];		
				a[i]=a[j];
				a[j]=tmp;
			} 
		}
	}

}
void bubblesort(int *a,int n){
	int i, j, temp;
	for (j = 0; j < n - 1; j++)
		for (i = 0; i < n - 1 - j; i++)
		{
			if(a[i] > a[i + 1])
			{
				temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
			}
		}

}
int main(){
	int a[10]={1,3,4,5,2,3,7,8,6,12};
	//bubblesort(a,9);
	qsort(a,0,9);
	for(int i=0;i<10;i++)
		cout<<a[i]<< " ";

}
