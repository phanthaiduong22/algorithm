void selectionsort(vector<int>a)
{
	int n=a.size();
	for(int i=0;i<n-1;i++)
		for(int j=n-1;j>i;j--)
			if(a[j]<a[j-1])
				swap(a[j],a[j-1]);
}