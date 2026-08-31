#include <stdio.h>
#include <stdlib.h>


//动态数组结构体
typedef struct{
    int* data;          //动态数组指针位置
    size_t size;        //数组尺寸
    size_t capacity;    //数组容量
}DynamicArray;


//初始化动态数组
void initDynamicArray(DynamicArray *array, size_t initialCapacity)
{
    array->data = (int *)malloc(initialCapacity *sizeof(int));          //分派初始化内存
    array->size = 0;
    array->capacity = initialCapacity;
}

//释放动态数组内存
void destroyDynamicArray(DynamicArray *array)
{
    free(array->data);        //释放动态数组内存
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
}

//调整动态数组内存大小
void resizeDynamicArray(DynamicArray *array, size_t newCapacity)
{
    int *newData = realloc(array->data, newCapacity * sizeof *newData);
    if (newData == NULL)
        return;  // 最好返回错误状态
    array->data = newData;
    array->capacity = newCapacity;
    // array->data = (int *)realloc(array->data, newCapacity *sizeof(int));   //调整内存大小
    // array->capacity = newCapacity;   //更新容量
}

//获取动态数组长度
size_t getLength(const DynamicArray *array)
{
    return array->size;
}

//指定位置插入新元素
void insertAt(DynamicArray *array, size_t index, int element)
{
    if(index > array->size)
    {
        return;
    }
    
    if(array->size >= array->capacity)   //如果容量不足扩大容量
    {   
        size_t newCapacity =  array->capacity == 0 ? 1 : array->capacity * 2;
        resizeDynamicArray(array, newCapacity);
    }
    for(size_t i = array->size; i > index; i--)
    {
        array->data[i] = array->data[i - 1];
    }
    array->data[index] = element; 
    array->size++;
}


//末尾插入元素
void insertEnd(DynamicArray *array, int element)
{
    insertAt(array, array->size, element);
}

//删除指定位置元素，并且返回元素
 int deleteAt(DynamicArray *array, size_t index)
 {
    if(index >= array->size)
    {
        return -1;
    }
    int deletElement;
    deletElement = array->data[index];
    for(size_t i = index; i + 1 < array->size; i++)
    {
        array->data[i] = array->data[i + 1];
    }
    // for(size_t i = index; i <= array->size; i++)
    // {
    //     array->data[i - 1] = array->data[i];
    // }
    array->size--;
    return deletElement;
 }

 //删除末尾元素并返回被删除的元素
 int deleteEnd(DynamicArray * array)
 {
    if(array->size == 0)
        return -1;
    return deleteAt(array, array->size - 1);
 }

// bool deleteAt(DynamicArray *array, size_t index, int *deletedElement)
// {
//     if (array == NULL || deletedElement == NULL ||
//         index >= array->size)
//     {
//         return false;
//     }

//     *deletedElement = array->data[index];

//     for (size_t i = index; i + 1 < array->size; i++)
//     {
//         array->data[i] = array->data[i + 1];
//     }

//     array->size--;
//     return true;
// }

// bool deleteEnd(DynamicArray *array, int *deletedElement)
// {
//     if (array == NULL || array->size == 0)
//     {
//         return false;
//     }

//     return deleteAt(array, array->size - 1, deletedElement);
// }
 //遍历所有元素
 void printArray(const DynamicArray *array)
 {
    for(int i = 0; i < array->size; i++)
    {
        printf("%d  ", array->data[i]);
    }
    printf("\n");
 }

int main()
{
    DynamicArray myArray;
    initDynamicArray(&myArray, 2);
    printf("Initialize a dynamic array with a capacity of 2.\n");
    //向动态数组尾部插入元素
    insertEnd(&myArray, 1);
    insertEnd(&myArray, 2);

    //打印数组当长度
    printf("The current length of the dynamic array is: %zu\n", getLength(&myArray));
    //索引1位置插入3
    insertAt(&myArray, 1, 3);
    printf("Insering 3 at index 1 fo a dynamic array.\n");

    //再打印数组当长度
    printf("The current length of the dynamic array is: %zu.\n", getLength(&myArray));

    //删除出索引1位置元素
    printf("Deleting element at index 1, and the element is :%d.\n", deleteAt(&myArray, 1));

    //删除末尾元素
    printf("Delating last elemnt at index, and the element is :%d.\n", deleteEnd(&myArray));

    printArray(&myArray);
    //释放动态数组内存
    destroyDynamicArray(&myArray);
}