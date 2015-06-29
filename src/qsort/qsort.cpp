void qsort(int *a,int low,int high){
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

class Qsort:public Allsort{
	public:
		void sort(int *a,int size){
			qsort(a,0,size);
			cout<<"this is quick sort"<<endl;
		}
};
