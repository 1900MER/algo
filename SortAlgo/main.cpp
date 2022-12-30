#include <iostream>
#include <vector>

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
    for(int i =1;i<size;i++){
        int preIndex = i-1;
        while(preIndex>=0 && array[preIndex]>array[i]){
            array[preIndex+1]  = array[preIndex];
            preIndex  = preIndex-1;
        }
        array[preIndex+1] = array[i];
    }
    return array;
}

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

std::vector<int> quickSort(std::vector<int> array){

}









int main() {
    std::vector<int> array = {0,5,4,3,6,8,10,2,4,8};
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
