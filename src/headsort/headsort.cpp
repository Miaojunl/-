void headadjust(int *a,int element,int size){
	int lchild=2*element;
	int rchild=2*element+1;
	int max=element;
	if(element<=size/2){
		if(a[lchild-1]>a[max-1] && lchild <=size){
			max=lchild;
		}
		if(a[rchild-1]>a[max-1] && rchild <= size){
			max=rchild;
		}
		if(max!=element){
			swap(a[element-1],a[max-1]);
			headadjust(a,max,size);
		}
	}
}
void bighead(int *a,int size){
	for(int i=size/2;i>=1;i--){
		headadjust(a,i,size);
	}
}

void headsort(int *a,int size){
	bighead(a,size);
	for(int i=size;i>=1;i--){
		swap(a[0],a[i-1]);
		headadjust(a,1,i-1);
	}
}

class Headsort:public Allsort{
	public:
		void sort(int *a,int n){
			headsort(a,n);
			cout<<"this is head sort"<<endl;
		}
};
