#include<iostream>
#include<cstring>
using namespace std; 
int main() 
{ 
int arr[] = {1,3,5,6,2,19,12};
int i = 0;
int size = (sizeof(arr)/sizeof(*arr));
while(i < size){
	int j = i-1;
	while(j >= 0){
		if(arr[i] < arr[j]){
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i--;
		}
		j--;
	}
	i++;
}
for(int i = 0;i < size;i++){ 
cout << arr[i] << endl;
}
return 0;
}
