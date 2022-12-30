#include <iostream>
#include <vector>
#include <tuple>

std::vector<int> bubbleSort(std::vector<int> array){
    auto a = array;
    int size = array.size();
    for(int i = 1; i <size;i++){
        for(int j = 0;j<size-i;j++){
            if (array[j]>array[j+1]){
                int temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
            }
        }
    }
    return array;
}

std::vector<int> selectSort(std::vector<int> array){
    int size = array.size();
    for(int i = 0; i <size-1;i++){
        int minIndex = i;
        for(int j = i+1;j<size;j++){
            if (array[j]<array[minIndex]){
                minIndex = j;
            }
        }
        int temp = array[minIndex];
        array[minIndex] = array[i];
        array[i] = temp;

    }
    return array;
}

std::vector<int> insertSort(std::vector<int> array){
    int size = array.size();
    int preIndex;
    for(int i = 1;i<size;i++){
        preIndex = i-1;
        auto current = array[i];
        while(preIndex>=0 && array[preIndex]>current){
            array[preIndex+1]  = array[preIndex];
            preIndex  = preIndex-1;
        }
        array[preIndex+1] = current;
    }
    return array;
}
// ----------------------------------------mergeSort----------------------------------------
std::vector<int> mergedArray(std::vector<int> left,std::vector<int> right){
    std::vector<int> result;
    int i,j =0;
    while(i < left.size() && j<right.size()) {

        if (left[i] <= right[j]) {
            result.push_back(left[i]);
            i++;
        }  else {
            result.push_back(right[j]);
            j++;
        }
    }
    while ( j<right.size() ) {
        result.push_back(right[j]);
        j++;
    }
    while ( i<left.size() ) {
        result.push_back(left[i]);
        i++;
    }
    return result;
}

std::vector<int> mergeSort(std::vector<int> array){
    if (array.size()<2){
        return array;
    }
    int mid = array.size()/2;
    std::vector<int> left(array.begin(),array.begin()+mid);
    std::vector<int> right(array.begin()+mid,array.end());
    return mergedArray(mergeSort(left), mergeSort(right));
}

// ----------------------------------------QuickSort----------------------------------------
int partition(std::vector<int>& array, int left, int right) {

    int i = left;

    for(int j = left;j<right;j++){
        if (array[j]<array[right]){
            std::swap(array[i],array[j]);
            i++;
        }
    }

    std::swap(array[i],array[right]);
    return i;
}

void quickSortRecur(std::vector<int>& array, int left, int right){
    if ( left>=right ) return;
    int pivot = partition(array,left,right);
    quickSortRecur(array,left,pivot-1);
    quickSortRecur(array,pivot+1,right);
}

std::vector<int> quickSort(std::vector<int>& array){
    quickSortRecur(array,0,array.size()-1);
    return array;
}






int main() {
    std::vector<int> array = {0,1,4,3,2,10,8,6};
    auto sortedArray4 = mergeSort(array);
    auto sortedArray1 = bubbleSort(array);
    auto sortedArray2 = selectSort(array);
    auto sortedArray3 = insertSort(array);
    auto sortedArray5 = quickSort(array);

    std::cout<<std::endl<< "Merge Sort: "<<std::endl;
    for(int i = 0;i<sortedArray4.size();i++) std::cout << sortedArray4[i] << " ";

    std::cout<<std::endl<< "Bubble Sort: "<<std::endl;
    for(int i = 0;i<sortedArray1.size();i++) std::cout << sortedArray1[i] << " ";

    std:: cout<<std::endl<< "Select Sort: "<<std::endl;
    for(int i = 0;i<sortedArray2.size();i++) std::cout << sortedArray2[i] << " ";

    std::cout<<std::endl<< "Insert Sort: "<<std::endl;
    for(int i = 0;i<sortedArray3.size();i++) std::cout << sortedArray3[i] << " ";

    std::cout<<std::endl<< "Quick Sort: "<<std::endl;
    for(int i = 0;i<sortedArray5.size();i++) std::cout << sortedArray5[i] << " ";





    return 0;
}
