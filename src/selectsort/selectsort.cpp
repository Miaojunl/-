class Selectsort:public Allsort{
	public:
		void sort(int *a,int n){
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
			cout<<"this is select sort "<<endl;
		}

};
